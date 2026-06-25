#include <gtest/gtest.h>
#include "../src/lib/elf.hpp"

/**
 * @brief helper function that just removes all extra white space in  a seequence down to a sigle space.
 * 
 * @param input 
 * @return std::string 
 */
std::string normalize_whitespace(const std::string& input)
{
    std::string output;
    bool last_was_space = false;

    for (char c : input)
    {
        if (std::isspace(static_cast<unsigned char>(c)))
        {
            if (!last_was_space)
            {
                output += ' ';
                last_was_space = true;
            }
        }
        else
        {
            output += c;
            last_was_space = false;
        }
    }

    return output;
}

/**
 * @brief exemplar test for comparison and understanding features of
 * gtest
 * 
 */
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

/**
 * @brief tests wheter or not the header extracted continues to output
 * the correct and consistent data
 * 
 */
TEST(ElfTests, ElfHeaderTest) {
  std::string expected = "E_ident array values: 7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00\n"
                         "Binary Type:                            64 bit elf\n"
                         "Endianess:                              Least Significant Bit (LSB)\n"
                         "Version:                                Current Version (0x01)\n"
                         "OS/ABI:                                 UNIX - System V\n"
                         "Type:                                   Executable file\n"
                         "Machine:                                AMD x86-64\n"
                         "Entry Point Address:                    0x400380\n"
                         "Program Headers Offset:                 64\n"
                         "Section Headers Offset:                 10472\n"
                         "Program Headers Offset:                 64\n"
                         "Flags:                                  0x0\n"
                         "Elf Headers Size:                       64\n"
                         "Program Header's Entry Size:            56\n"
                         "Program Header's Entry Count:           13\n"
                         "Section Header's Entry Size:            64\n"
                         "Section Header's Entry Count:           32\n"
                         "Section Header's String table index:    31\n";
  
  std::string testBin_filepath = "./test/bins/hello";
  Elf testBinary(testBin_filepath);
  std::string result = testBinary.print_headers();

  EXPECT_EQ(
    normalize_whitespace(expected), 
    normalize_whitespace(result));
}

TEST(ElfTests, ElfSectionHeaderTest) {
  std::string expected = R"(Name: 
	Type: Unused section entry
	Flags: NONE
	Virtual Address: 0
	File offset: 0 (bytes)
	Section Size: 0 (bytes)

Name: .note.gnu.build-id
	Type: Note section
	Flags: SHF_ALLOC
	Virtual Address: 400318
	File offset: 792 (bytes)
	Section Size: 36 (bytes)

Name: .init
	Type: Program data
	Flags: SHF_ALLOC | SHF_EXECINSTR
	Virtual Address: 40033c
	File offset: 828 (bytes)
	Section Size: 27 (bytes)

Name: .plt
	Type: Program data
	Flags: SHF_ALLOC | SHF_EXECINSTR
	Virtual Address: 400360
	File offset: 864 (bytes)
	Section Size: 32 (bytes)

Name: .text
	Type: Program data
	Flags: SHF_ALLOC | SHF_EXECINSTR
	Virtual Address: 400380
	File offset: 896 (bytes)
	Section Size: 251 (bytes)

Name: .fini
	Type: Program data
	Flags: SHF_ALLOC | SHF_EXECINSTR
	Virtual Address: 40047c
	File offset: 1148 (bytes)
	Section Size: 13 (bytes)

Name: .interp
	Type: Program data
	Flags: SHF_ALLOC
	Virtual Address: 401000
	File offset: 4096 (bytes)
	Section Size: 28 (bytes)

Name: .gnu.hash
	Type: Unknown section type
	Flags: SHF_ALLOC
	Virtual Address: 401020
	File offset: 4128 (bytes)
	Section Size: 28 (bytes)

Name: .dynsym
	Type: Dynamic linker symbol table
	Flags: SHF_ALLOC
	Virtual Address: 401040
	File offset: 4160 (bytes)
	Section Size: 96 (bytes)

Name: .dynstr
	Type: String table
	Flags: SHF_ALLOC
	Virtual Address: 4010a0
	File offset: 4256 (bytes)
	Section Size: 72 (bytes)

Name: .gnu.version
	Type: OS-specific (high bound)
	Flags: SHF_ALLOC
	Virtual Address: 4010e8
	File offset: 4328 (bytes)
	Section Size: 8 (bytes)

Name: .gnu.version_r
	Type: Unknown section type
	Flags: SHF_ALLOC
	Virtual Address: 4010f0
	File offset: 4336 (bytes)
	Section Size: 48 (bytes)

Name: .rela.dyn
	Type: Relocation entries with addends
	Flags: SHF_ALLOC
	Virtual Address: 401120
	File offset: 4384 (bytes)
	Section Size: 48 (bytes)

Name: .rela.plt
	Type: Relocation entries with addends
	Flags: SHF_ALLOC | SHF_INFO_LINK
	Virtual Address: 401150
	File offset: 4432 (bytes)
	Section Size: 24 (bytes)

Name: .rodata
	Type: Program data
	Flags: SHF_ALLOC
	Virtual Address: 401168
	File offset: 4456 (bytes)
	Section Size: 29 (bytes)

Name: .eh_frame_hdr
	Type: Program data
	Flags: SHF_ALLOC
	Virtual Address: 401188
	File offset: 4488 (bytes)
	Section Size: 44 (bytes)

Name: .eh_frame
	Type: Program data
	Flags: SHF_ALLOC
	Virtual Address: 4011b8
	File offset: 4536 (bytes)
	Section Size: 140 (bytes)

Name: .note.gnu.property
	Type: Note section
	Flags: SHF_ALLOC
	Virtual Address: 401248
	File offset: 4680 (bytes)
	Section Size: 64 (bytes)

Name: .note.ABI-tag
	Type: Note section
	Flags: SHF_ALLOC
	Virtual Address: 401288
	File offset: 4744 (bytes)
	Section Size: 32 (bytes)

Name: .init_array
	Type: Constructor function array
	Flags: SHF_WRITE | SHF_ALLOC
	Virtual Address: 402df8
	File offset: 7672 (bytes)
	Section Size: 8 (bytes)

Name: .fini_array
	Type: Destructor function array
	Flags: SHF_WRITE | SHF_ALLOC
	Virtual Address: 402e00
	File offset: 7680 (bytes)
	Section Size: 8 (bytes)

Name: .dynamic
	Type: Dynamic linking information
	Flags: SHF_WRITE | SHF_ALLOC
	Virtual Address: 402e08
	File offset: 7688 (bytes)
	Section Size: 464 (bytes)

Name: .got
	Type: Program data
	Flags: SHF_WRITE | SHF_ALLOC
	Virtual Address: 402fd8
	File offset: 8152 (bytes)
	Section Size: 16 (bytes)

Name: .got.plt
	Type: Program data
	Flags: SHF_WRITE | SHF_ALLOC
	Virtual Address: 402fe8
	File offset: 8168 (bytes)
	Section Size: 32 (bytes)

Name: .data
	Type: Program data
	Flags: SHF_WRITE | SHF_ALLOC
	Virtual Address: 403008
	File offset: 8200 (bytes)
	Section Size: 4 (bytes)

Name: .bss
	Type: No file contents (.bss)
	Flags: SHF_WRITE | SHF_ALLOC
	Virtual Address: 40300c
	File offset: 8204 (bytes)
	Section Size: 4 (bytes)

Name: .comment
	Type: Program data
	Flags: SHF_MERGE | SHF_STRINGS
	Virtual Address: 0
	File offset: 8204 (bytes)
	Section Size: 46 (bytes)

Name: .annobin.notes
	Type: Program data
	Flags: SHF_MERGE | SHF_STRINGS
	Virtual Address: 0
	File offset: 8250 (bytes)
	Section Size: 335 (bytes)

Name: .gnu.build.attributes
	Type: Note section
	Flags: NONE
	Virtual Address: 405010
	File offset: 8588 (bytes)
	Section Size: 324 (bytes)

Name: .symtab
	Type: Symbol table
	Flags: NONE
	Virtual Address: 0
	File offset: 8912 (bytes)
	Section Size: 816 (bytes)

Name: .strtab
	Type: String table
	Flags: NONE
	Virtual Address: 0
	File offset: 9728 (bytes)
	Section Size: 426 (bytes)

Name: .shstrtab
	Type: String table
	Flags: NONE
	Virtual Address: 0
	File offset: 10154 (bytes)
	Section Size: 315 (bytes)
)";

  std::string testBin_filepath = "./test/bins/hello";
  Elf testBinary(testBin_filepath);
  std::string result = testBinary.print_s_headers();

  EXPECT_EQ(
    normalize_whitespace(expected), 
    normalize_whitespace(result));
}

TEST(ElfTests, ElfProgramHeaderTest){
	std::string expected = R"(Segment: 
	Type:PHDR
	Permissions: R--
	Virtual Address: 400040
	File offset: 64 (bytes)
	Physical Address: 400040
	File Size: 2d8
	Memory Size: 2d8
	Align: 8
Segment: 
	Type:INTERP
	Permissions: R--
	Virtual Address: 401000
	File offset: 4096 (bytes)
	Physical Address: 401000
	File Size: 1c
	Memory Size: 1c
	Align: 1
Segment: 
	Type:LOAD
	Permissions: R-X
	Virtual Address: 400000
	File offset: 0 (bytes)
	Physical Address: 400000
	File Size: 489
	Memory Size: 489
	Align: 1000
Segment: 
	Type:LOAD
	Permissions: R--
	Virtual Address: 401000
	File offset: 4096 (bytes)
	Physical Address: 401000
	File Size: 2a8
	Memory Size: 2a8
	Align: 1000
Segment: 
	Type:LOAD
	Permissions: RW-
	Virtual Address: 402df8
	File offset: 7672 (bytes)
	Physical Address: 402df8
	File Size: 214
	Memory Size: 218
	Align: 1000
Segment: 
	Type:DYN
	Permissions: RW-
	Virtual Address: 402e08
	File offset: 7688 (bytes)
	Physical Address: 402e08
	File Size: 1d0
	Memory Size: 1d0
	Align: 8
Segment: 
	Type:NOTE
	Permissions: R--
	Virtual Address: 400318
	File offset: 792 (bytes)
	Physical Address: 400318
	File Size: 24
	Memory Size: 24
	Align: 4
Segment: 
	Type:NOTE
	Permissions: R--
	Virtual Address: 401248
	File offset: 4680 (bytes)
	Physical Address: 401248
	File Size: 40
	Memory Size: 40
	Align: 8
Segment: 
	Type:NOTE
	Permissions: R--
	Virtual Address: 401288
	File offset: 4744 (bytes)
	Physical Address: 401288
	File Size: 20
	Memory Size: 20
	Align: 4
Segment: 
	Type:UNK
	Permissions: R--
	Virtual Address: 401248
	File offset: 4680 (bytes)
	Physical Address: 401248
	File Size: 40
	Memory Size: 40
	Align: 8
Segment: 
	Type:UNK
	Permissions: R--
	Virtual Address: 401188
	File offset: 4488 (bytes)
	Physical Address: 401188
	File Size: 2c
	Memory Size: 2c
	Align: 4
Segment: 
	Type:UNK
	Permissions: RW-
	Virtual Address: 0
	File offset: 0 (bytes)
	Physical Address: 0
	File Size: 0
	Memory Size: 0
	Align: 10
Segment: 
	Type:UNK
	Permissions: R--
	Virtual Address: 402df8
	File offset: 7672 (bytes)
	Physical Address: 402df8
	File Size: 208
	Memory Size: 208
	Align: 1
)";
	std::string testBin_filepath = "./test/bins/hello";
  	Elf testBinary(testBin_filepath);
  	std::string result = testBinary.print_p_headers();

  	EXPECT_EQ(normalize_whitespace(expected), 
    		normalize_whitespace(result));
}

TEST(ElfTests, ElfStringTableParsingTest) {
	std::string expected = R"(Name: .dynstr
----------------------------------------------------------------------------------------------------
0. puts
1. __libc_start_main
2. libc.so.6
3. GLIBC_2.2.5
4. GLIBC_2.34
5. __gmon_start__
Name: .strtab
----------------------------------------------------------------------------------------------------
0. crt1.o
1. __abi_tag
2. crtbegin.o
3. deregister_tm_clones
4. __do_global_dtors_aux
5. completed.0
6. __do_global_dtors_aux_fini_array_entry
7. frame_dummy
8. __frame_dummy_init_array_entry
9. hello.c
10. crtend.o
11. __FRAME_END__
12. _DYNAMIC
13. __GNU_EH_FRAME_HDR
14. _GLOBAL_OFFSET_TABLE_
15. __libc_start_main@GLIBC_2.34
16. puts@GLIBC_2.2.5
17. _edata
18. _fini
19. __data_start
20. __gmon_start__
21. __dso_handle
22. _IO_stdin_used
23. _end
24. _dl_relocate_static_pie
25. __bss_start
26. main
27. __TMC_END__
28. _init
Name: .shstrtab
----------------------------------------------------------------------------------------------------
0. .symtab
1. .strtab
2. .shstrtab
3. .note.gnu.build-id
4. .init
5. .text
6. .fini
7. .interp
8. .gnu.hash
9. .dynsym
10. .dynstr
11. .gnu.version
12. .gnu.version_r
13. .rela.dyn
14. .rela.plt
15. .rodata
16. .eh_frame_hdr
17. .eh_frame
18. .note.gnu.property
19. .note.ABI-tag
20. .init_array
21. .fini_array
22. .dynamic
23. .got
24. .got.plt
25. .data
26. .bss
27. .comment
28. .annobin.notes
29. .gnu.build.attributes
)";
	std::string testBin_filepath = "./test/bins/hello";
  	Elf testBinary(testBin_filepath);
  	std::string result = testBinary.print_bin_strings();

  	EXPECT_EQ(normalize_whitespace(expected), 
    		normalize_whitespace(result));
}
