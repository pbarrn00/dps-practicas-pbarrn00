
 
# 5. Realiza un analisis estatico del codigo erroneo y copia en tu solucion el resultado.
 * Utiliza las herramientas:
 *   (a) rats
 *   (b) cppchecker
 *   (c) splint
 *   (d) vera++
 *   (e) valgrind


## --> rats example3.cpp <--

rats example3_broken.cpp
Entries in perl database: 33
Entries in ruby database: 46
Entries in python database: 62
Entries in c database: 334
Entries in php database: 55
Analyzing example3_broken.cpp
Total lines analyzed: 16
Total time 0.000142 seconds
112676 lines per second

## --> cpp check <--

cppcheck --enable=all --inconclusive --library=posix example3_broken.cpp 
Checking example3_broken.cpp ...
[example3_broken.cpp:5]: (style) The function 'func' is never used.
(information) Cppcheck cannot find all the include files (use --check-config for details)

## --> splint <--

splint example3_broken.cpp 
Splint 3.1.2 --- 05 Sep 2017

Command Line: Unrecognized file extension:
                 example3_broken.cpp (assuming .cpp is C source code)
  warn when command line file does not have a recognized extension (Use
  -fileextensions to inhibit warning)
example3_broken.cpp: (in function func)
example3_broken.cpp:11:14: Fall through case (no preceding break)
  Execution falls through from the previous case (use /*@fallthrough@*/ to mark
  fallthrough cases). (Use -casebreak to inhibit warning)
example3_broken.cpp:13:17: Fall through case (no preceding break)
example3_broken.cpp:8:19: Statement after switch is not a case: int i = 4
  The first statement after a switch is not a case. (Use -firstcase to inhibit
  warning)
Finished checking --- 3 code warnings

## --> vera ++ <--

vera++ example3_broken.cpp 
example3_broken.cpp:1: no copyright notice found
example3_broken.cpp:10: trailing whitespace
example3_broken.cpp:14: comma should be followed by whitespace
example3_broken.cpp:15: closing curly bracket not in the same line or column
example3_broken.cpp:16: no newline at end of file
example3_broken.cpp:16: closing curly bracket not in the same line or column

## --> valgrind <--

valgrind --leak-check=full ./example3.o
==5992== Memcheck, a memory error detector
==5992== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==5992== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==5992== Command: ./example3.o
==5992== 
--5992-- WARNING: Serious error when reading debug info
--5992-- When reading debug info from /usr/lib/arm-linux-gnueabihf/ld-2.28.so:
--5992-- Ignoring non-Dwarf2/3/4 block in .debug_info
--5992-- WARNING: Serious error when reading debug info
--5992-- When reading debug info from /usr/lib/arm-linux-gnueabihf/ld-2.28.so:
--5992-- Last block truncated in .debug_info; ignoring
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401A5B0: index (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401A5B4: index (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4007F0C: _dl_dst_count (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4008154: expand_dynamic_string_token (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401AA60: strlen (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401AA64: strlen (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4017F90: malloc (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4017F9C: malloc (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B5C8: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B5E8: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B5F8: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B614: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B61C: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B644: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B644: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B66C: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B680: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B684: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B690: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x40180CC: calloc (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4017FD0: malloc (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401A148: mmap (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Syscall param mmap2(start) contains uninitialised byte(s)
==5992==    at 0x401A15C: mmap (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Syscall param mmap2(length) contains uninitialised byte(s)
==5992==    at 0x401A15C: mmap (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Syscall param mmap2(offset) contains uninitialised byte(s)
==5992==    at 0x401A15C: mmap (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4017F6C: malloc (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400BC9C: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B5D4: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B610: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BC48: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BC64: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401A9F4: strdup (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B640: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B640: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B668: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4008CEC: _dl_map_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Syscall param openat(filename) contains uninitialised byte(s)
==5992==    at 0x4019F34: __open64_nocancel (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401810C: free (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400BA50: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BA68: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BA88: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BA8C: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BAAC: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BB1C: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BB30: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BB74: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BB8C: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401AA10: strlen (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401AA28: strlen (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B608: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400BC68: _dl_new_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4005FD0: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4005FFC: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4006008: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4006088: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x40060D4: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x40060D8: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4006264: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x40062F8: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4006314: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400634C: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4006C90: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400640C: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4011020: _dl_name_match_p (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4011034: _dl_name_match_p (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401A600: strcmp (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4011028: _dl_name_match_p (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4013688: _dl_get_origin (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401369C: _dl_get_origin (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x40081F8: expand_dynamic_string_token (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x40081B0: expand_dynamic_string_token (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4007FE0: _dl_dst_substitute (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401A65C: strcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4008064: _dl_dst_substitute (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4009138: _dl_map_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B780: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B68C: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B690: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B694: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4006218: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4006258: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B628: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
--5992-- WARNING: Serious error when reading debug info
--5992-- When reading debug info from /usr/lib/arm-linux-gnueabihf/libm-2.28.so:
--5992-- Ignoring non-Dwarf2/3/4 block in .debug_info
--5992-- WARNING: Serious error when reading debug info
--5992-- When reading debug info from /usr/lib/arm-linux-gnueabihf/libm-2.28.so:
--5992-- Last block truncated in .debug_info; ignoring
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B64C: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B64C: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B674: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B8E0: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B670: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4006204: _dl_map_object_from_fd (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
--5992-- WARNING: Serious error when reading debug info
--5992-- When reading debug info from /usr/lib/arm-linux-gnueabihf/libc-2.28.so:
--5992-- Ignoring non-Dwarf2/3/4 block in .debug_info
--5992-- WARNING: Serious error when reading debug info
--5992-- When reading debug info from /usr/lib/arm-linux-gnueabihf/libc-2.28.so:
--5992-- Last block truncated in .debug_info; ignoring
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400E428: _dl_map_object_deps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400E43C: _dl_map_object_deps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B664: memcpy (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400E808: _dl_map_object_deps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400E838: _dl_map_object_deps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400E870: _dl_map_object_deps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401600C: _dl_sort_maps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401602C: _dl_sort_maps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400EC04: _dl_map_object_deps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4003834: dl_main (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4003848: dl_main (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4003884: dl_main (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== 
==5992== More than 100 errors detected.  Subsequent errors
==5992== will still be recorded, but in less detail than before.
==5992== Use of uninitialised value of size 4
==5992==    at 0x40038B4: dl_main (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4003910: dl_main (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4011418: _dl_check_map_versions (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4011434: _dl_check_map_versions (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401144C: _dl_check_map_versions (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401185C: _dl_check_map_versions (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x40118D0: _dl_check_map_versions (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401194C: _dl_check_map_versions (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x40010B0: init_tls (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x40010DC: init_tls (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4012B40: _dl_determine_tlsoffset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012B44: _dl_determine_tlsoffset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012B50: _dl_determine_tlsoffset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012B5C: _dl_determine_tlsoffset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012C50: _dl_determine_tlsoffset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4018018: malloc (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4012D68: _dl_allocate_tls_storage (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401BAB4: __udivsi3 (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B540: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B548: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B560: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x401B560: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B568: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B570: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B578: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B57C: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B588: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B590: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B598: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B5A0: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x401B5A4: memset (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012D94: _dl_allocate_tls_storage (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4012700: allocate_dtv (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012700: allocate_dtv (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012704: allocate_dtv (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4012DA4: _dl_allocate_tls_storage (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4001104: init_tls (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400110C: init_tls (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Syscall param set_tls(addr) contains uninitialised byte(s)
==5992==    at 0x4001120: init_tls (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4003CB0: dl_main (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4003CB8: dl_main (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400CA48: _dl_relocate_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400A6DC: _dl_lookup_symbol_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A6F4: _dl_lookup_symbol_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009C50: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4009C24: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009C28: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4009C5C: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009C78: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009BA0: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009BAC: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009BE0: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009E1C: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009E2C: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009E84: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x40099F4: check_match (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x40099F8: check_match (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009A0C: check_match (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009A14: check_match (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009A24: check_match (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009AC8: check_match (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009ACC: check_match (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A7B8: _dl_lookup_symbol_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A7C8: _dl_lookup_symbol_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400CBC0: _dl_relocate_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400CC74: _dl_relocate_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A738: _dl_lookup_symbol_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4011004: _dl_name_match_p (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4011018: _dl_name_match_p (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4013448: _dl_add_to_slotinfo (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4013468: _dl_add_to_slotinfo (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4009FE8: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400A11C: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A244: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A250: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A258: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400A038: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A09C: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A0C8: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400A38C: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A3C4: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400A3C0: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A3D0: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A3F0: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A418: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400A424: do_lookup_x (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400CB4C: _dl_relocate_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400D8F0: _dl_relocate_object (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4012DE4: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012DEC: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012DF4: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012E3C: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012E68: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012E74: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012EA8: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012ED4: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012EF8: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4012F54: _dl_allocate_tls_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4010400: _dl_init (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400FA2C: _dl_fixup (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x400FAB8: _dl_fixup (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x400FAB8: _dl_fixup (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4015B74: _dl_runtime_resolve (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x48F6000: std::error_category::error_category() (in /usr/lib/arm-linux-gnueabihf/libstdc++.so.6.0.25)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x48F66B4: __aeabi_atexit (in /usr/lib/arm-linux-gnueabihf/libstdc++.so.6.0.25)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4AAAB1C: __cxa_atexit (in /usr/lib/arm-linux-gnueabihf/libc-2.28.so)
==5992== 
17
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x40105FC: _dl_fini (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x40161A0: _dl_sort_maps (in /usr/lib/arm-linux-gnueabihf/ld-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4923570: std::_V2::error_category::~error_category() (in /usr/lib/arm-linux-gnueabihf/libstdc++.so.6.0.25)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x48F6024: std::error_category::~error_category() (in /usr/lib/arm-linux-gnueabihf/libstdc++.so.6.0.25)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4AEF880: free (in /usr/lib/arm-linux-gnueabihf/libc-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4B958B0: free_mem (in /usr/lib/arm-linux-gnueabihf/libc-2.28.so)
==5992== 
==5992== Conditional jump or move depends on uninitialised value(s)
==5992==    at 0x4B95930: free_mem (in /usr/lib/arm-linux-gnueabihf/libc-2.28.so)
==5992== 
==5992== Use of uninitialised value of size 4
==5992==    at 0x4B957C4: free_slotinfo (in /usr/lib/arm-linux-gnueabihf/libc-2.28.so)
==5992== 
==5992== 
==5992== HEAP SUMMARY:
==5992==     in use at exit: 20,224 bytes in 1 blocks
==5992==   total heap usage: 2 allocs, 1 frees, 21,248 bytes allocated
==5992== 
==5992== LEAK SUMMARY:
==5992==    definitely lost: 0 bytes in 0 blocks
==5992==    indirectly lost: 0 bytes in 0 blocks
==5992==      possibly lost: 0 bytes in 0 blocks
==5992==    still reachable: 20,224 bytes in 1 blocks
==5992==         suppressed: 0 bytes in 0 blocks
==5992== Reachable blocks (those to which a pointer was found) are not shown.
==5992== To see them, rerun with: --leak-check=full --show-reachable=yes
==5992== 
==5992== For counts of detected and suppressed errors, rerun with: -v
==5992== Use --track-origins=yes to see where uninitialised values come from
==5992== ERROR SUMMARY: 89330 errors from 214 contexts (suppressed: 2011 from 2)