if "test" in COMMAND_LINE_TARGETS:
    SConscript("test/SConscript")
else:
    Program("hello", [ "index.c", Glob("src/*.c") ])
