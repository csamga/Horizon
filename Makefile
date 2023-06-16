# ╭--------------------------╮ #
# │ EDIT THE FOLLOWING LINES │ #
# ╰--------------------------╯ #

# C compiler
CC := gcc

# Archiver
AR := ar

# C compiler flags
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpedantic
CFLAGS += -pedantic-errors
CFLAGS += -O0
CFLAGS += -std=c99
CFLAGS += -ggdb3

# Binaries
horizon = horizon

# Directories
horizon_dir := horizon

src_dir := $(horizon_dir)/src
inc_dir := $(horizon_dir)/include
build_dir := $(horizon_dir)/build
bin_dir := $(horizon_dir)/bin
deps_dir := $(horizon_dir)/deps

# Standard include directories
inc_dirs := $(inc_dir)

# System include directories
sys_inc_dirs :=

# Precompiled header sources
pch_src := $(src_dir)/pch.h

# Defines
defines := DEBUG _DEBUG

# Library directories
library_dirs :=

# Linked libraries
libraries :=

# ╭-----------------------------╮ #
# │ DO NOT EDIT AFTER THIS LINE │ #
# ╰-----------------------------╯ #

# Prefixed binaries
horizon := $(patsubst %,lib%.a,$(horizon))
horizon := $(addprefix $(bin_dir)/,$(horizon))

# Source files
src := $(wildcard $(src_dir)/*.c)

# Object files
obj := $(patsubst $(src_dir)/%.c,$(build_dir)/%.o,$(src))

# Precompiled header objects
pch_obj := $(patsubst %.h,%.gch,$(pch_src))

# Dependencies
obj_deps := $(patsubst $(build_dir)/%.o,$(deps_dir)/%.d,$(obj))
pch_deps := $(patsubst $(src_dir)/%.gch,$(deps_dir)/%.d,$(pch_obj))

# Include flags
inc_flags = $(addprefix -I,$(inc_dirs)) $(addprefix -isystem,$(sys_inc_dirs))

# Defines flags
def_flags := $(addprefix -D,$(defines))

# Dependency flags
dep_flags := -MMD -MF
obj_dep_flags = $(dep_flags) $(patsubst $(build_dir)/%.o,$(deps_dir)/%.d,$@)
pch_dep_flags = $(dep_flags) $(patsubst $(src_dir)/%.gch,$(deps_dir)/%.d,$@)

# Preprocessor flags
CPPFLAGS = $(inc_flags) $(def_flags)

# Linker flags
LDFLAGS := $(addprefix -L,$(library_dirs))

# Libs flags
LDLIBS := $(addprefix -l,$(patsubst lib%.a,%,$(libraries)))

# ╭---------╮ #
# │ TARGETS │ #
# ╰---------╯ #

# Default target: run 'make'
all: $(horizon)
	@echo $(done_building)

$(horizon): $(obj)
	@echo $(linking)
	@mkdir -p $(@D)
	$(AR) rvs $(LDFLAGS) $@ $^ $(LDLIBS)

$(build_dir)/%.o: $(src_dir)/%.c $(pch_obj) | $(deps_dir)
	@echo $(compiling)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -include $(pch_src) $(obj_dep_flags) -c -o $@ $<

-include $(obj_deps)

$(pch_obj): $(pch_src) | $(deps_dir)
	@echo $(compiling)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(pch_dep_flags) -x c-header -c -o $@ $<

-include $(pch_deps)

$(deps_dir):
	@mkdir -p $@

clean:
	@echo $(cleaning)
	$(RM) $(bin_dir)/*
	$(RM) $(build_dir)/*.o
	$(RM) $(obj_deps)

cleaner: clean
	$(RM) $(pch_obj)
	$(RM) $(pch_deps)

remake: cleaner all

info:
	@echo $(info)
	@echo -e "$(cyan)horizon:$(reset) $(horizon)"
	@echo -e "$(cyan)src dir:$(reset) $(src_dir)"
	@echo -e "$(cyan)build dir:$(reset) $(build_dir)"
	@echo -e "$(cyan)deps dir:$(reset) $(deps_dir)"
	@echo -e "$(cyan)bin dir:$(reset) $(bin_dir)"
	@echo -e "$(cyan)sources:$(reset) $(src)"
	@echo -e "$(cyan)objects:$(reset) $(obj)"
	@echo -e "$(cyan)dependencies:$(reset) $(deps)"

	@echo -e "$(cyan)lib dir:$(reset) $(lib_dir)"
	@echo -e "$(cyan)linked libraries:$(reset) $(libraries)"
	@echo -e "$(cyan)include dirs:$(reset) $(inc_dirs)"
	@echo -e "$(cyan)defines:$(reset) $(defines)"
	@echo -e "$(cyan)compiler:$(reset) $(CC)"
	@echo -e "$(cyan)archiver:$(reset) $(AR)"
	@echo -e "$(cyan)compiler flags:$(reset) $(CFLAGS)"
	@echo -e "$(cyan)preprocessor flags:$(reset) $(CPPFLAGS)"
	@echo -e "$(cyan)linker flags:$(reset) $(LDFLAGS)"
	@echo -e "$(cyan)linked libraries flags:$(reset) $(LDLIBS)"

# Non-file targets
.PHONY: all clean cleaner remake info

# Prompts
done_building = -e "$(green)$(invert) Done building $(reset) $(green)$^$(reset)"
linking = -e "$(cyan)$(invert) Linking $(reset) $(cyan)$^$(reset)"
compiling = -e "$(cyan)$(invert) Compiling $(reset) $(cyan)$<$(reset)"
running = -e "$(magenta)$(invert) Running $(reset) $(magenta)$<$(reset)"
cleaning = -e "$(red)$(invert) Cleaning $(reset)"
info = -e "$(cyan)$(invert) Info $(reset)"

# ANSI escape sequences
reset := \e[m
invert := \e[7m
red := \e[91m
green := \e[92m
blue := \e[94m
magenta := \e[95m
cyan := \e[96m
