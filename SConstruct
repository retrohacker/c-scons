if "test" in COMMAND_LINE_TARGETS:
    SConscript("test/SConscript")
else:
    Program("main", ["index.c", Glob("src/*.c")])
