import os

TARGETS = [
    {
        "TARG"  : "windows_x86_64",
        "CC"    : "x86_64-w64-mingw32-gcc",
        "CXX"   : "x86_64-w64-mingw32-g++",
        "LD"    : "x86_64-w64-mingw32-g++",
        "AR"    : "x86_64-w64-mingw32-ar",
        "STRIP" : "x86_64-w64-mingw32-strip",
    },
    {
        "TARG"  : "windows_i686",
        "CC"    : "i686-w64-mingw32-gcc",
        "CXX"   : "i686-w64-mingw32-g++",
        "LD"    : "i686-w64-mingw32-g++",
        "AR"    : "i686-w64-mingw32-ar",
        "STRIP" : "i686-w64-mingw32-strip",
    },
    {
        "TARG"  : "linux_x86_64",
        "CC"    : "gcc",
        "CXX"   : "g++",
        "LD"    : "g++",
        "AR"    : "ar",
        "STRIP" : "strip",
    }
]

if "test" in COMMAND_LINE_TARGETS:
    SConscript("test/SConscript")
else:
    for target in TARGETS:
        dir = "build/" + target["TARG"]
        del target["TARG"]
        os.system("mkdir -p " + dir)
        os.system("cp -r index.c src " + dir)
        env = Environment(**target)
        env.Append(ENV = { 'Path' : os.environ['PATH'] })
        env.Program(dir + "/logger", [dir + "/index.c", Glob(dir + "/src/*.c")])
        env.Clean(dir + "/logger", "build")
