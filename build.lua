#! /usr/bin/env lua

local GLFW_DIR = "deps/glfw-3.4"
local host = io.popen("uname -s"):read("*l")

local is_release = false
for i = 1, #arg do
   if arg[i] == "--release" then
      is_release = true
      break
   end
end

local build_flags = is_release and "-O2" or "-g -O0 -DDEBUG_MODE"
local app_name    = is_release and "handmade_hero" or "handmade_hero_debug"

local build_for_linux = table.concat({
    "g++ ",
    "-Wall -Wextra --std=c++17",
    build_flags,
    "-I ./"..GLFW_DIR.."/include",
    "-o "..app_name,
    "src/win32_handmade.cpp",
    GLFW_DIR.."/build/src/libglfw3.a",
    "-lGL -lm",
}, " ")

local build_cmd

if host == "Linux" then
   if is_release then
      print("Building for linux.")
   else
      print("Building for linux in DEBUG_MODE")
   end
   build_cmd = build_for_linux
else
   print("This platform is not supported yet.")
   os.exit(1)
end

os.execute("rm -f handmade_hero handmade_hero_debug")

print("RUNNING: " .. build_cmd)
os.execute(build_cmd)

print("Is release? " .. (is_release and "yes" or "no"))
