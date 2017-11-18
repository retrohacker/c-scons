if "test" in COMMAND_LINE_TARGETS:
    SConscript("test/SConscript")
else:
    Program("main", [
        "index.c",
        "deps/minibsdiff/bsdiff.c",
        "deps/minibsdiff/bspatch.c",
        Glob("src/*.c")
    ])
