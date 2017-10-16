AddOption("--test",
          type="choice",
          default="no",
          choices=["yes", "no"])
if GetOption("test") == "yes":
    SConscript("test/SConscript")
else:
    Program("hello", [ "index.c", Glob("src/*.c") ])
