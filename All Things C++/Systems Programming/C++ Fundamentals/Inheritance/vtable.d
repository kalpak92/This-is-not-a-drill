
vtable:	file format mach-o 64-bit x86-64

Disassembly of section __TEXT,__text:

00000001000010e0 <_main>:
; int main(int argc, char** argv) {
1000010e0: 55                          	pushq	%rbp
1000010e1: 48 89 e5                    	movq	%rsp, %rbp
1000010e4: 48 83 ec 20                 	subq	$32, %rsp
1000010e8: 89 7d fc                    	movl	%edi, -4(%rbp)
1000010eb: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
;     Der1 d1;
1000010ef: 48 8d 7d e8                 	leaq	-24(%rbp), %rdi
1000010f3: e8 28 00 00 00              	callq	0x100001120 <Der1::Der1()>
;     d1.f1();
1000010f8: 48 8d 7d e8                 	leaq	-24(%rbp), %rdi
1000010fc: e8 3f 00 00 00              	callq	0x100001140 <Der1::f1()>
;     Base* bptr = &d1;
100001101: 48 8d 45 e8                 	leaq	-24(%rbp), %rax
100001105: 48 89 45 e0                 	movq	%rax, -32(%rbp)
;     bptr->f1();
100001109: 48 8b 7d e0                 	movq	-32(%rbp), %rdi
10000110d: 48 8b 07                    	movq	(%rdi), %rax
100001110: ff 10                       	callq	*(%rax)
; }
100001112: 31 c0                       	xorl	%eax, %eax
100001114: 48 83 c4 20                 	addq	$32, %rsp
100001118: 5d                          	popq	%rbp
100001119: c3                          	retq
10000111a: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)

0000000100001120 <Der1::Der1()>:
; class Der1: public Base {
100001120: 55                          	pushq	%rbp
100001121: 48 89 e5                    	movq	%rsp, %rbp
100001124: 48 83 ec 10                 	subq	$16, %rsp
100001128: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
10000112c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001130: e8 4b 00 00 00              	callq	0x100001180 <Der1::Der1()>
100001135: 48 83 c4 10                 	addq	$16, %rsp
100001139: 5d                          	popq	%rbp
10000113a: c3                          	retq
10000113b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001140 <Der1::f1()>:
;         virtual void f1() {
100001140: 55                          	pushq	%rbp
100001141: 48 89 e5                    	movq	%rsp, %rbp
100001144: 48 83 ec 10                 	subq	$16, %rsp
100001148: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
;             std::cout << "Der1::f1()" << std::endl;
10000114c: 48 8b 3d f5 0e 00 00        	movq	3829(%rip), %rdi        ## 0x100002048 <_strlen+0x100002048>
100001153: 48 8d 35 d8 0d 00 00        	leaq	3544(%rip), %rsi        ## 0x100001f32 <_strlen+0x100001f32>
10000115a: e8 01 01 00 00              	callq	0x100001260 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<[abi:ue170006]<std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*)>
10000115f: 48 89 c7                    	movq	%rax, %rdi
100001162: 48 8d 35 57 01 00 00        	leaq	343(%rip), %rsi         ## 0x1000012c0 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::endl[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&)>
100001169: e8 32 01 00 00              	callq	0x1000012a0 <std::__1::basic_ostream<char, std::__1::char_traits<char>>::operator<<[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>& (*)(std::__1::basic_ostream<char, std::__1::char_traits<char>>&))>
;         }
10000116e: 48 83 c4 10                 	addq	$16, %rsp
100001172: 5d                          	popq	%rbp
100001173: c3                          	retq
100001174: 66 66 66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)

0000000100001180 <Der1::Der1()>:
; class Der1: public Base {
100001180: 55                          	pushq	%rbp
100001181: 48 89 e5                    	movq	%rsp, %rbp
100001184: 48 83 ec 10                 	subq	$16, %rsp
100001188: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
10000118c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001190: 48 89 7d f0                 	movq	%rdi, -16(%rbp)
100001194: e8 27 00 00 00              	callq	0x1000011c0 <Base::Base()>
100001199: 48 8b 45 f0                 	movq	-16(%rbp), %rax
10000119d: 48 8d 0d fc 0e 00 00        	leaq	3836(%rip), %rcx        ## 0x1000020a0 <vtable for Der1>
1000011a4: 48 83 c1 10                 	addq	$16, %rcx
1000011a8: 48 89 08                    	movq	%rcx, (%rax)
1000011ab: 48 83 c4 10                 	addq	$16, %rsp
1000011af: 5d                          	popq	%rbp
1000011b0: c3                          	retq
1000011b1: 66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00	nopw	%cs:(%rax,%rax)

00000001000011c0 <Base::Base()>:
; class Base {
1000011c0: 55                          	pushq	%rbp
1000011c1: 48 89 e5                    	movq	%rsp, %rbp
1000011c4: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
1000011c8: 48 8b 45 f8                 	movq	-8(%rbp), %rax
1000011cc: 48 8d 0d 15 0f 00 00        	leaq	3861(%rip), %rcx        ## 0x1000020e8 <vtable for Base>
1000011d3: 48 83 c1 10                 	addq	$16, %rcx
1000011d7: 48 89 08                    	movq	%rcx, (%rax)
1000011da: 5d                          	popq	%rbp
1000011db: c3                          	retq
1000011dc: 0f 1f 40 00                 	nopl	(%rax)

00000001000011e0 <Base::f2()>:
;         virtual void f2() {
1000011e0: 55                          	pushq	%rbp
1000011e1: 48 89 e5                    	movq	%rsp, %rbp
1000011e4: 48 83 ec 10                 	subq	$16, %rsp
1000011e8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
;             std::cout << "Base::f2()" << std::endl;
1000011ec: 48 8b 3d 55 0e 00 00        	movq	3669(%rip), %rdi        ## 0x100002048 <_strlen+0x100002048>
1000011f3: 48 8d 35 2d 0d 00 00        	leaq	3373(%rip), %rsi        ## 0x100001f27 <_strlen+0x100001f27>
1000011fa: e8 61 00 00 00              	callq	0x100001260 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<[abi:ue170006]<std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*)>
1000011ff: 48 89 c7                    	movq	%rax, %rdi
100001202: 48 8d 35 b7 00 00 00        	leaq	183(%rip), %rsi         ## 0x1000012c0 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::endl[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&)>
100001209: e8 92 00 00 00              	callq	0x1000012a0 <std::__1::basic_ostream<char, std::__1::char_traits<char>>::operator<<[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>& (*)(std::__1::basic_ostream<char, std::__1::char_traits<char>>&))>
;         }
10000120e: 48 83 c4 10                 	addq	$16, %rsp
100001212: 5d                          	popq	%rbp
100001213: c3                          	retq
100001214: 66 66 66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)

0000000100001220 <Base::f1()>:
;         virtual void f1() {
100001220: 55                          	pushq	%rbp
100001221: 48 89 e5                    	movq	%rsp, %rbp
100001224: 48 83 ec 10                 	subq	$16, %rsp
100001228: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
;             std::cout << "Base::f1()" << std::endl;
10000122c: 48 8b 3d 15 0e 00 00        	movq	3605(%rip), %rdi        ## 0x100002048 <_strlen+0x100002048>
100001233: 48 8d 35 e2 0c 00 00        	leaq	3298(%rip), %rsi        ## 0x100001f1c <_strlen+0x100001f1c>
10000123a: e8 21 00 00 00              	callq	0x100001260 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<[abi:ue170006]<std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*)>
10000123f: 48 89 c7                    	movq	%rax, %rdi
100001242: 48 8d 35 77 00 00 00        	leaq	119(%rip), %rsi         ## 0x1000012c0 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::endl[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&)>
100001249: e8 52 00 00 00              	callq	0x1000012a0 <std::__1::basic_ostream<char, std::__1::char_traits<char>>::operator<<[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>& (*)(std::__1::basic_ostream<char, std::__1::char_traits<char>>&))>
;         }
10000124e: 48 83 c4 10                 	addq	$16, %rsp
100001252: 5d                          	popq	%rbp
100001253: c3                          	retq
100001254: 66 66 66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)

0000000100001260 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<[abi:ue170006]<std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*)>:
; {
100001260: 55                          	pushq	%rbp
100001261: 48 89 e5                    	movq	%rsp, %rbp
100001264: 48 83 ec 20                 	subq	$32, %rsp
100001268: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
10000126c: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
;     return _VSTD::__put_character_sequence(__os, __str, _Traits::length(__str));
100001270: 48 8b 45 f8                 	movq	-8(%rbp), %rax
100001274: 48 89 45 e0                 	movq	%rax, -32(%rbp)
100001278: 48 8b 45 f0                 	movq	-16(%rbp), %rax
10000127c: 48 89 45 e8                 	movq	%rax, -24(%rbp)
100001280: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
100001284: e8 77 02 00 00              	callq	0x100001500 <std::__1::char_traits<char>::length[abi:ue170006](char const*)>
100001289: 48 8b 7d e0                 	movq	-32(%rbp), %rdi
10000128d: 48 8b 75 e8                 	movq	-24(%rbp), %rsi
100001291: 48 89 c2                    	movq	%rax, %rdx
100001294: e8 77 00 00 00              	callq	0x100001310 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)>
100001299: 48 83 c4 20                 	addq	$32, %rsp
10000129d: 5d                          	popq	%rbp
10000129e: c3                          	retq
10000129f: 90                          	nop

00000001000012a0 <std::__1::basic_ostream<char, std::__1::char_traits<char>>::operator<<[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>& (*)(std::__1::basic_ostream<char, std::__1::char_traits<char>>&))>:
;     { return __pf(*this); }
1000012a0: 55                          	pushq	%rbp
1000012a1: 48 89 e5                    	movq	%rsp, %rbp
1000012a4: 48 83 ec 10                 	subq	$16, %rsp
1000012a8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
1000012ac: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
1000012b0: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
1000012b4: ff 55 f0                    	callq	*-16(%rbp)
1000012b7: 48 83 c4 10                 	addq	$16, %rsp
1000012bb: 5d                          	popq	%rbp
1000012bc: c3                          	retq
1000012bd: 0f 1f 00                    	nopl	(%rax)

00000001000012c0 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::endl[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&)>:
; {
1000012c0: 55                          	pushq	%rbp
1000012c1: 48 89 e5                    	movq	%rsp, %rbp
1000012c4: 48 83 ec 10                 	subq	$16, %rsp
1000012c8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
;     __os.put(__os.widen('\n'));
1000012cc: 48 8b 45 f8                 	movq	-8(%rbp), %rax
1000012d0: 48 89 45 f0                 	movq	%rax, -16(%rbp)
1000012d4: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
1000012d8: 48 8b 07                    	movq	(%rdi), %rax
1000012db: 48 03 78 e8                 	addq	-24(%rax), %rdi
1000012df: be 0a 00 00 00              	movl	$10, %esi
1000012e4: e8 d7 09 00 00              	callq	0x100001cc0 <std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:ue170006](char) const>
1000012e9: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
1000012ed: 0f be f0                    	movsbl	%al, %esi
1000012f0: e8 24 0b 00 00              	callq	0x100001e19 <_strlen+0x100001e19>
;     __os.flush();
1000012f5: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
1000012f9: e8 21 0b 00 00              	callq	0x100001e1f <_strlen+0x100001e1f>
;     return __os;
1000012fe: 48 8b 45 f8                 	movq	-8(%rbp), %rax
100001302: 48 83 c4 10                 	addq	$16, %rsp
100001306: 5d                          	popq	%rbp
100001307: c3                          	retq
100001308: 0f 1f 84 00 00 00 00 00     	nopl	(%rax,%rax)

0000000100001310 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)>:
; {
100001310: 55                          	pushq	%rbp
100001311: 48 89 e5                    	movq	%rsp, %rbp
100001314: 48 81 ec 90 00 00 00        	subq	$144, %rsp
10000131b: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
10000131f: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
100001323: 48 89 55 e8                 	movq	%rdx, -24(%rbp)
;         typename basic_ostream<_CharT, _Traits>::sentry __s(__os);
100001327: 48 8b 75 f8                 	movq	-8(%rbp), %rsi
10000132b: 48 8d 7d d8                 	leaq	-40(%rbp), %rdi
10000132f: e8 f1 0a 00 00              	callq	0x100001e25 <_strlen+0x100001e25>
100001334: e9 00 00 00 00              	jmp	0x100001339 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x29>
100001339: 48 8d 7d d8                 	leaq	-40(%rbp), %rdi
;         if (__s)
10000133d: e8 fe 01 00 00              	callq	0x100001540 <std::__1::basic_ostream<char, std::__1::char_traits<char>>::sentry::operator bool[abi:ue170006]() const>
100001342: 88 45 b7                    	movb	%al, -73(%rbp)
100001345: e9 00 00 00 00              	jmp	0x10000134a <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x3a>
10000134a: 8a 45 b7                    	movb	-73(%rbp), %al
;         if (__s)
10000134d: a8 01                       	testb	$1, %al
10000134f: 0f 85 05 00 00 00           	jne	0x10000135a <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x4a>
100001355: e9 2f 01 00 00              	jmp	0x100001489 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x179>
;             if (std::__pad_and_output(_Ip(__os),
10000135a: 48 8b 75 f8                 	movq	-8(%rbp), %rsi
10000135e: 48 8d 7d b8                 	leaq	-72(%rbp), %rdi
100001362: e8 19 04 00 00              	callq	0x100001780 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>::ostreambuf_iterator[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>&)>
;                                       __str,
100001367: 48 8b 45 f0                 	movq	-16(%rbp), %rax
10000136b: 48 89 45 a8                 	movq	%rax, -88(%rbp)
;                                       (__os.flags() & ios_base::adjustfield) == ios_base::left ?
10000136f: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001373: 48 8b 07                    	movq	(%rdi), %rax
100001376: 48 8b 40 e8                 	movq	-24(%rax), %rax
10000137a: 48 01 c7                    	addq	%rax, %rdi
10000137d: e8 2e 04 00 00              	callq	0x1000017b0 <std::__1::ios_base::flags[abi:ue170006]() const>
100001382: 89 45 b0                    	movl	%eax, -80(%rbp)
100001385: e9 00 00 00 00              	jmp	0x10000138a <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x7a>
10000138a: 8b 45 b0                    	movl	-80(%rbp), %eax
;                                       (__os.flags() & ios_base::adjustfield) == ios_base::left ?
10000138d: 25 b0 00 00 00              	andl	$176, %eax
100001392: 83 f8 20                    	cmpl	$32, %eax
100001395: 0f 85 11 00 00 00           	jne	0x1000013ac <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x9c>
;                                           __str + __len :
10000139b: 48 8b 45 f0                 	movq	-16(%rbp), %rax
10000139f: 48 03 45 e8                 	addq	-24(%rbp), %rax
1000013a3: 48 89 45 a0                 	movq	%rax, -96(%rbp)
;                                       (__os.flags() & ios_base::adjustfield) == ios_base::left ?
1000013a7: e9 08 00 00 00              	jmp	0x1000013b4 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0xa4>
;                                           __str,
1000013ac: 48 8b 45 f0                 	movq	-16(%rbp), %rax
1000013b0: 48 89 45 a0                 	movq	%rax, -96(%rbp)
1000013b4: 48 8b 45 a0                 	movq	-96(%rbp), %rax
1000013b8: 48 89 45 80                 	movq	%rax, -128(%rbp)
;                                       __str + __len,
1000013bc: 48 8b 45 f0                 	movq	-16(%rbp), %rax
1000013c0: 48 8b 4d e8                 	movq	-24(%rbp), %rcx
1000013c4: 48 01 c8                    	addq	%rcx, %rax
1000013c7: 48 89 45 88                 	movq	%rax, -120(%rbp)
;                                       __os,
1000013cb: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
1000013cf: 48 8b 07                    	movq	(%rdi), %rax
1000013d2: 48 8b 40 e8                 	movq	-24(%rax), %rax
1000013d6: 48 01 c7                    	addq	%rax, %rdi
1000013d9: 48 89 7d 90                 	movq	%rdi, -112(%rbp)
;                                       __os.fill()).failed())
1000013dd: e8 ee 03 00 00              	callq	0x1000017d0 <std::__1::basic_ios<char, std::__1::char_traits<char>>::fill[abi:ue170006]() const>
1000013e2: 88 45 9f                    	movb	%al, -97(%rbp)
1000013e5: e9 00 00 00 00              	jmp	0x1000013ea <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0xda>
1000013ea: 4c 8b 45 90                 	movq	-112(%rbp), %r8
1000013ee: 48 8b 4d 88                 	movq	-120(%rbp), %rcx
1000013f2: 48 8b 55 80                 	movq	-128(%rbp), %rdx
1000013f6: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
1000013fa: 8a 45 9f                    	movb	-97(%rbp), %al
;             if (std::__pad_and_output(_Ip(__os),
1000013fd: 48 8b 7d b8                 	movq	-72(%rbp), %rdi
100001401: 44 0f be c8                 	movsbl	%al, %r9d
100001405: e8 56 01 00 00              	callq	0x100001560 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)>
10000140a: 48 89 85 78 ff ff ff        	movq	%rax, -136(%rbp)
100001411: e9 00 00 00 00              	jmp	0x100001416 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x106>
100001416: 48 8b 85 78 ff ff ff        	movq	-136(%rbp), %rax
;             if (std::__pad_and_output(_Ip(__os),
10000141d: 48 89 45 c0                 	movq	%rax, -64(%rbp)
;                                       __os.fill()).failed())
100001421: 48 8d 7d c0                 	leaq	-64(%rbp), %rdi
100001425: e8 16 04 00 00              	callq	0x100001840 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>::failed[abi:ue170006]() const>
;             if (std::__pad_and_output(_Ip(__os),
10000142a: a8 01                       	testb	$1, %al
10000142c: 0f 85 05 00 00 00           	jne	0x100001437 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x127>
100001432: e9 4d 00 00 00              	jmp	0x100001484 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x174>
;                 __os.setstate(ios_base::badbit | ios_base::failbit);
100001437: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
10000143b: 48 8b 07                    	movq	(%rdi), %rax
10000143e: 48 8b 40 e8                 	movq	-24(%rax), %rax
100001442: 48 01 c7                    	addq	%rax, %rdi
100001445: be 05 00 00 00              	movl	$5, %esi
10000144a: e8 11 04 00 00              	callq	0x100001860 <std::__1::basic_ios<char, std::__1::char_traits<char>>::setstate[abi:ue170006](unsigned int)>
10000144f: e9 00 00 00 00              	jmp	0x100001454 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x144>
100001454: e9 2b 00 00 00              	jmp	0x100001484 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x174>
100001459: 48 89 c1                    	movq	%rax, %rcx
; }
10000145c: 89 d0                       	movl	%edx, %eax
10000145e: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100001462: 89 45 cc                    	movl	%eax, -52(%rbp)
100001465: e9 37 00 00 00              	jmp	0x1000014a1 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x191>
10000146a: 48 89 c1                    	movq	%rax, %rcx
; }
10000146d: 89 d0                       	movl	%edx, %eax
10000146f: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100001473: 89 45 cc                    	movl	%eax, -52(%rbp)
100001476: 48 8d 7d d8                 	leaq	-40(%rbp), %rdi
;     }
10000147a: e8 ac 09 00 00              	callq	0x100001e2b <_strlen+0x100001e2b>
10000147f: e9 18 00 00 00              	jmp	0x10000149c <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x18c>
;         }
100001484: e9 00 00 00 00              	jmp	0x100001489 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x179>
100001489: 48 8d 7d d8                 	leaq	-40(%rbp), %rdi
;     }
10000148d: e8 99 09 00 00              	callq	0x100001e2b <_strlen+0x100001e2b>
100001492: e9 00 00 00 00              	jmp	0x100001497 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x187>
100001497: e9 2b 00 00 00              	jmp	0x1000014c7 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x1b7>
10000149c: e9 00 00 00 00              	jmp	0x1000014a1 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x191>
1000014a1: 48 8b 7d d0                 	movq	-48(%rbp), %rdi
1000014a5: e8 9f 09 00 00              	callq	0x100001e49 <_strlen+0x100001e49>
;         __os.__set_badbit_and_consider_rethrow();
1000014aa: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
1000014ae: 48 8b 07                    	movq	(%rdi), %rax
1000014b1: 48 8b 40 e8                 	movq	-24(%rax), %rax
1000014b5: 48 01 c7                    	addq	%rax, %rdi
1000014b8: e8 7a 09 00 00              	callq	0x100001e37 <_strlen+0x100001e37>
1000014bd: e9 00 00 00 00              	jmp	0x1000014c2 <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x1b2>
;     }
1000014c2: e8 8e 09 00 00              	callq	0x100001e55 <_strlen+0x100001e55>
;     return __os;
1000014c7: 48 8b 45 f8                 	movq	-8(%rbp), %rax
1000014cb: 48 81 c4 90 00 00 00        	addq	$144, %rsp
1000014d2: 5d                          	popq	%rbp
1000014d3: c3                          	retq
1000014d4: 48 89 c1                    	movq	%rax, %rcx
; }
1000014d7: 89 d0                       	movl	%edx, %eax
1000014d9: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
1000014dd: 89 45 cc                    	movl	%eax, -52(%rbp)
;     }
1000014e0: e8 70 09 00 00              	callq	0x100001e55 <_strlen+0x100001e55>
1000014e5: e9 00 00 00 00              	jmp	0x1000014ea <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x1da>
1000014ea: e9 00 00 00 00              	jmp	0x1000014ef <std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long)+0x1df>
1000014ef: 48 8b 7d d0                 	movq	-48(%rbp), %rdi
1000014f3: e8 03 09 00 00              	callq	0x100001dfb <_strlen+0x100001dfb>
1000014f8: 48 89 c7                    	movq	%rax, %rdi
;     }
1000014fb: e8 90 03 00 00              	callq	0x100001890 <___clang_call_terminate>

0000000100001500 <std::__1::char_traits<char>::length[abi:ue170006](char const*)>:
;     static inline _LIBCPP_HIDE_FROM_ABI size_t _LIBCPP_CONSTEXPR_SINCE_CXX17 length(const char_type* __s)  _NOEXCEPT {
100001500: 55                          	pushq	%rbp
100001501: 48 89 e5                    	movq	%rsp, %rbp
100001504: 48 83 ec 20                 	subq	$32, %rsp
100001508: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
;       return std::__constexpr_strlen(__s);
10000150c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001510: e8 cb 08 00 00              	callq	0x100001de0 <std::__1::__constexpr_strlen[abi:ue170006](char const*)>
100001515: 48 89 45 e0                 	movq	%rax, -32(%rbp)
100001519: e9 00 00 00 00              	jmp	0x10000151e <std::__1::char_traits<char>::length[abi:ue170006](char const*)+0x1e>
10000151e: 48 8b 45 e0                 	movq	-32(%rbp), %rax
;       return std::__constexpr_strlen(__s);
100001522: 48 83 c4 20                 	addq	$32, %rsp
100001526: 5d                          	popq	%rbp
100001527: c3                          	retq
100001528: 48 89 c1                    	movq	%rax, %rcx
;     }
10000152b: 89 d0                       	movl	%edx, %eax
10000152d: 48 89 4d f0                 	movq	%rcx, -16(%rbp)
100001531: 89 45 ec                    	movl	%eax, -20(%rbp)
;       return std::__constexpr_strlen(__s);
100001534: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
100001538: e8 12 09 00 00              	callq	0x100001e4f <_strlen+0x100001e4f>
10000153d: 0f 1f 00                    	nopl	(%rax)

0000000100001540 <std::__1::basic_ostream<char, std::__1::char_traits<char>>::sentry::operator bool[abi:ue170006]() const>:
;     explicit operator bool() const {return __ok_;}
100001540: 55                          	pushq	%rbp
100001541: 48 89 e5                    	movq	%rsp, %rbp
100001544: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001548: 48 8b 45 f8                 	movq	-8(%rbp), %rax
10000154c: 8a 00                       	movb	(%rax), %al
10000154e: 24 01                       	andb	$1, %al
100001550: 0f b6 c0                    	movzbl	%al, %eax
100001553: 5d                          	popq	%rbp
100001554: c3                          	retq
100001555: 66 66 2e 0f 1f 84 00 00 00 00 00    	nopw	%cs:(%rax,%rax)

0000000100001560 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)>:
; {
100001560: 55                          	pushq	%rbp
100001561: 48 89 e5                    	movq	%rsp, %rbp
100001564: 48 81 ec 90 00 00 00        	subq	$144, %rsp
10000156b: 44 88 c8                    	movb	%r9b, %al
10000156e: 48 89 7d f0                 	movq	%rdi, -16(%rbp)
100001572: 48 89 75 e8                 	movq	%rsi, -24(%rbp)
100001576: 48 89 55 e0                 	movq	%rdx, -32(%rbp)
10000157a: 48 89 4d d8                 	movq	%rcx, -40(%rbp)
10000157e: 4c 89 45 d0                 	movq	%r8, -48(%rbp)
100001582: 88 45 cf                    	movb	%al, -49(%rbp)
;     if (__s.__sbuf_ == nullptr)
100001585: 48 83 7d f0 00              	cmpq	$0, -16(%rbp)
10000158a: 0f 85 0d 00 00 00           	jne	0x10000159d <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x3d>
;         return __s;
100001590: 48 8b 45 f0                 	movq	-16(%rbp), %rax
100001594: 48 89 45 f8                 	movq	%rax, -8(%rbp)
100001598: e9 c2 01 00 00              	jmp	0x10000175f <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x1ff>
;     streamsize __sz = __oe - __ob;
10000159d: 48 8b 45 d8                 	movq	-40(%rbp), %rax
1000015a1: 48 8b 4d e8                 	movq	-24(%rbp), %rcx
1000015a5: 48 29 c8                    	subq	%rcx, %rax
1000015a8: 48 89 45 c0                 	movq	%rax, -64(%rbp)
;     streamsize __ns = __iob.width();
1000015ac: 48 8b 7d d0                 	movq	-48(%rbp), %rdi
1000015b0: e8 eb 02 00 00              	callq	0x1000018a0 <std::__1::ios_base::width[abi:ue170006]() const>
1000015b5: 48 89 45 b8                 	movq	%rax, -72(%rbp)
;     if (__ns > __sz)
1000015b9: 48 8b 45 b8                 	movq	-72(%rbp), %rax
1000015bd: 48 3b 45 c0                 	cmpq	-64(%rbp), %rax
1000015c1: 0f 8e 14 00 00 00           	jle	0x1000015db <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x7b>
;         __ns -= __sz;
1000015c7: 48 8b 4d c0                 	movq	-64(%rbp), %rcx
1000015cb: 48 8b 45 b8                 	movq	-72(%rbp), %rax
1000015cf: 48 29 c8                    	subq	%rcx, %rax
1000015d2: 48 89 45 b8                 	movq	%rax, -72(%rbp)
1000015d6: e9 08 00 00 00              	jmp	0x1000015e3 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x83>
;         __ns = 0;
1000015db: 48 c7 45 b8 00 00 00 00     	movq	$0, -72(%rbp)
;     streamsize __np = __op - __ob;
1000015e3: 48 8b 45 e0                 	movq	-32(%rbp), %rax
1000015e7: 48 8b 4d e8                 	movq	-24(%rbp), %rcx
1000015eb: 48 29 c8                    	subq	%rcx, %rax
1000015ee: 48 89 45 b0                 	movq	%rax, -80(%rbp)
;     if (__np > 0)
1000015f2: 48 83 7d b0 00              	cmpq	$0, -80(%rbp)
1000015f7: 0f 8e 35 00 00 00           	jle	0x100001632 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0xd2>
;         if (__s.__sbuf_->sputn(__ob, __np) != __np)
1000015fd: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
100001601: 48 8b 75 e8                 	movq	-24(%rbp), %rsi
100001605: 48 8b 55 b0                 	movq	-80(%rbp), %rdx
100001609: e8 b2 02 00 00              	callq	0x1000018c0 <std::__1::basic_streambuf<char, std::__1::char_traits<char>>::sputn[abi:ue170006](char const*, long)>
10000160e: 48 3b 45 b0                 	cmpq	-80(%rbp), %rax
100001612: 0f 84 15 00 00 00           	je	0x10000162d <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0xcd>
;             __s.__sbuf_ = nullptr;
100001618: 48 c7 45 f0 00 00 00 00     	movq	$0, -16(%rbp)
;             return __s;
100001620: 48 8b 45 f0                 	movq	-16(%rbp), %rax
100001624: 48 89 45 f8                 	movq	%rax, -8(%rbp)
100001628: e9 32 01 00 00              	jmp	0x10000175f <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x1ff>
;     }
10000162d: e9 00 00 00 00              	jmp	0x100001632 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0xd2>
;     if (__ns > 0)
100001632: 48 83 7d b8 00              	cmpq	$0, -72(%rbp)
100001637: 0f 8e be 00 00 00           	jle	0x1000016fb <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x19b>
;         basic_string<_CharT, _Traits> __sp(__ns, __fl);
10000163d: 48 8b 75 b8                 	movq	-72(%rbp), %rsi
100001641: 0f be 55 cf                 	movsbl	-49(%rbp), %edx
100001645: 48 8d 7d 98                 	leaq	-104(%rbp), %rdi
100001649: 48 89 bd 70 ff ff ff        	movq	%rdi, -144(%rbp)
100001650: e8 9b 02 00 00              	callq	0x1000018f0 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::basic_string[abi:ue170006](unsigned long, char)>
100001655: 48 8b bd 70 ff ff ff        	movq	-144(%rbp), %rdi
;         if (__s.__sbuf_->sputn(__sp.data(), __ns) != __ns)
10000165c: 48 8b 45 f0                 	movq	-16(%rbp), %rax
100001660: 48 89 85 78 ff ff ff        	movq	%rax, -136(%rbp)
100001667: e8 b4 02 00 00              	callq	0x100001920 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::data[abi:ue170006]() const>
10000166c: 48 8b bd 78 ff ff ff        	movq	-136(%rbp), %rdi
100001673: 48 89 c6                    	movq	%rax, %rsi
100001676: 48 8b 55 b8                 	movq	-72(%rbp), %rdx
10000167a: e8 41 02 00 00              	callq	0x1000018c0 <std::__1::basic_streambuf<char, std::__1::char_traits<char>>::sputn[abi:ue170006](char const*, long)>
10000167f: 48 89 45 80                 	movq	%rax, -128(%rbp)
100001683: e9 00 00 00 00              	jmp	0x100001688 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x128>
100001688: 48 8b 45 80                 	movq	-128(%rbp), %rax
;         if (__s.__sbuf_->sputn(__sp.data(), __ns) != __ns)
10000168c: 48 3b 45 b8                 	cmpq	-72(%rbp), %rax
100001690: 0f 84 36 00 00 00           	je	0x1000016cc <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x16c>
;             __s.__sbuf_ = nullptr;
100001696: 48 c7 45 f0 00 00 00 00     	movq	$0, -16(%rbp)
;             return __s;
10000169e: 48 8b 45 f0                 	movq	-16(%rbp), %rax
1000016a2: 48 89 45 f8                 	movq	%rax, -8(%rbp)
1000016a6: c7 45 88 01 00 00 00        	movl	$1, -120(%rbp)
1000016ad: e9 21 00 00 00              	jmp	0x1000016d3 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x173>
1000016b2: 48 89 c1                    	movq	%rax, %rcx
; }
1000016b5: 89 d0                       	movl	%edx, %eax
1000016b7: 48 89 4d 90                 	movq	%rcx, -112(%rbp)
1000016bb: 89 45 8c                    	movl	%eax, -116(%rbp)
1000016be: 48 8d 7d 98                 	leaq	-104(%rbp), %rdi
;     }
1000016c2: e8 4c 07 00 00              	callq	0x100001e13 <_strlen+0x100001e13>
1000016c7: e9 2a 00 00 00              	jmp	0x1000016f6 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x196>
1000016cc: c7 45 88 00 00 00 00        	movl	$0, -120(%rbp)
1000016d3: 48 8d 7d 98                 	leaq	-104(%rbp), %rdi
;     }
1000016d7: e8 37 07 00 00              	callq	0x100001e13 <_strlen+0x100001e13>
1000016dc: 8b 45 88                    	movl	-120(%rbp), %eax
1000016df: 85 c0                       	testl	%eax, %eax
1000016e1: 0f 84 0a 00 00 00           	je	0x1000016f1 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x191>
1000016e7: e9 00 00 00 00              	jmp	0x1000016ec <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x18c>
1000016ec: e9 6e 00 00 00              	jmp	0x10000175f <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x1ff>
;     }
1000016f1: e9 05 00 00 00              	jmp	0x1000016fb <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x19b>
1000016f6: e9 71 00 00 00              	jmp	0x10000176c <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x20c>
;     __np = __oe - __op;
1000016fb: 48 8b 45 d8                 	movq	-40(%rbp), %rax
1000016ff: 48 8b 4d e0                 	movq	-32(%rbp), %rcx
100001703: 48 29 c8                    	subq	%rcx, %rax
100001706: 48 89 45 b0                 	movq	%rax, -80(%rbp)
;     if (__np > 0)
10000170a: 48 83 7d b0 00              	cmpq	$0, -80(%rbp)
10000170f: 0f 8e 35 00 00 00           	jle	0x10000174a <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x1ea>
;         if (__s.__sbuf_->sputn(__op, __np) != __np)
100001715: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
100001719: 48 8b 75 e0                 	movq	-32(%rbp), %rsi
10000171d: 48 8b 55 b0                 	movq	-80(%rbp), %rdx
100001721: e8 9a 01 00 00              	callq	0x1000018c0 <std::__1::basic_streambuf<char, std::__1::char_traits<char>>::sputn[abi:ue170006](char const*, long)>
100001726: 48 3b 45 b0                 	cmpq	-80(%rbp), %rax
10000172a: 0f 84 15 00 00 00           	je	0x100001745 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x1e5>
;             __s.__sbuf_ = nullptr;
100001730: 48 c7 45 f0 00 00 00 00     	movq	$0, -16(%rbp)
;             return __s;
100001738: 48 8b 45 f0                 	movq	-16(%rbp), %rax
10000173c: 48 89 45 f8                 	movq	%rax, -8(%rbp)
100001740: e9 1a 00 00 00              	jmp	0x10000175f <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x1ff>
;     }
100001745: e9 00 00 00 00              	jmp	0x10000174a <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:ue170006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char)+0x1ea>
;     __iob.width(0);
10000174a: 48 8b 7d d0                 	movq	-48(%rbp), %rdi
10000174e: 31 c0                       	xorl	%eax, %eax
100001750: 89 c6                       	movl	%eax, %esi
100001752: e8 f9 01 00 00              	callq	0x100001950 <std::__1::ios_base::width[abi:ue170006](long)>
;     return __s;
100001757: 48 8b 45 f0                 	movq	-16(%rbp), %rax
10000175b: 48 89 45 f8                 	movq	%rax, -8(%rbp)
; }
10000175f: 48 8b 45 f8                 	movq	-8(%rbp), %rax
100001763: 48 81 c4 90 00 00 00        	addq	$144, %rsp
10000176a: 5d                          	popq	%rbp
10000176b: c3                          	retq
;     }
10000176c: 48 8b 7d 90                 	movq	-112(%rbp), %rdi
100001770: e8 86 06 00 00              	callq	0x100001dfb <_strlen+0x100001dfb>
100001775: 48 89 c7                    	movq	%rax, %rdi
;     }
100001778: e8 13 01 00 00              	callq	0x100001890 <___clang_call_terminate>
10000177d: 0f 0b                       	ud2
10000177f: 90                          	nop

0000000100001780 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>::ostreambuf_iterator[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>&)>:
;         : __sbuf_(__s.rdbuf()) {}
100001780: 55                          	pushq	%rbp
100001781: 48 89 e5                    	movq	%rsp, %rbp
100001784: 48 83 ec 10                 	subq	$16, %rsp
100001788: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
10000178c: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
100001790: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001794: 48 8b 75 f0                 	movq	-16(%rbp), %rsi
100001798: e8 53 04 00 00              	callq	0x100001bf0 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>::ostreambuf_iterator[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>&)>
10000179d: 48 83 c4 10                 	addq	$16, %rsp
1000017a1: 5d                          	popq	%rbp
1000017a2: c3                          	retq
1000017a3: 66 66 66 66 2e 0f 1f 84 00 00 00 00 00      	nopw	%cs:(%rax,%rax)

00000001000017b0 <std::__1::ios_base::flags[abi:ue170006]() const>:
; {
1000017b0: 55                          	pushq	%rbp
1000017b1: 48 89 e5                    	movq	%rsp, %rbp
1000017b4: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
1000017b8: 48 8b 45 f8                 	movq	-8(%rbp), %rax
;     return __fmtflags_;
1000017bc: 8b 40 08                    	movl	8(%rax), %eax
1000017bf: 5d                          	popq	%rbp
1000017c0: c3                          	retq
1000017c1: 66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00	nopw	%cs:(%rax,%rax)

00000001000017d0 <std::__1::basic_ios<char, std::__1::char_traits<char>>::fill[abi:ue170006]() const>:
; {
1000017d0: 55                          	pushq	%rbp
1000017d1: 48 89 e5                    	movq	%rsp, %rbp
1000017d4: 48 83 ec 10                 	subq	$16, %rsp
1000017d8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
1000017dc: 48 8b 45 f8                 	movq	-8(%rbp), %rax
1000017e0: 48 89 45 f0                 	movq	%rax, -16(%rbp)
;     if (traits_type::eq_int_type(traits_type::eof(), __fill_))
1000017e4: e8 c7 04 00 00              	callq	0x100001cb0 <std::__1::char_traits<char>::eof[abi:ue170006]()>
1000017e9: 89 c7                       	movl	%eax, %edi
1000017eb: 48 8b 45 f0                 	movq	-16(%rbp), %rax
1000017ef: 8b b0 90 00 00 00           	movl	144(%rax), %esi
1000017f5: e8 96 04 00 00              	callq	0x100001c90 <std::__1::char_traits<char>::eq_int_type[abi:ue170006](int, int)>
1000017fa: a8 01                       	testb	$1, %al
1000017fc: 0f 85 05 00 00 00           	jne	0x100001807 <std::__1::basic_ios<char, std::__1::char_traits<char>>::fill[abi:ue170006]() const+0x37>
100001802: e9 1d 00 00 00              	jmp	0x100001824 <std::__1::basic_ios<char, std::__1::char_traits<char>>::fill[abi:ue170006]() const+0x54>
100001807: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
;         __fill_ = widen(' ');
10000180b: be 20 00 00 00              	movl	$32, %esi
100001810: e8 ab 04 00 00              	callq	0x100001cc0 <std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:ue170006](char) const>
100001815: 88 c1                       	movb	%al, %cl
100001817: 48 8b 45 f0                 	movq	-16(%rbp), %rax
10000181b: 0f be c9                    	movsbl	%cl, %ecx
10000181e: 89 88 90 00 00 00           	movl	%ecx, 144(%rax)
100001824: 48 8b 45 f0                 	movq	-16(%rbp), %rax
;     return __fill_;
100001828: 8b 80 90 00 00 00           	movl	144(%rax), %eax
10000182e: 0f be c0                    	movsbl	%al, %eax
100001831: 48 83 c4 10                 	addq	$16, %rsp
100001835: 5d                          	popq	%rbp
100001836: c3                          	retq
100001837: 66 0f 1f 84 00 00 00 00 00  	nopw	(%rax,%rax)

0000000100001840 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>::failed[abi:ue170006]() const>:
;     _LIBCPP_INLINE_VISIBILITY bool failed() const _NOEXCEPT {return __sbuf_ == nullptr;}
100001840: 55                          	pushq	%rbp
100001841: 48 89 e5                    	movq	%rsp, %rbp
100001844: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001848: 48 8b 45 f8                 	movq	-8(%rbp), %rax
10000184c: 48 83 38 00                 	cmpq	$0, (%rax)
100001850: 0f 94 c0                    	sete	%al
100001853: 24 01                       	andb	$1, %al
100001855: 0f b6 c0                    	movzbl	%al, %eax
100001858: 5d                          	popq	%rbp
100001859: c3                          	retq
10000185a: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)

0000000100001860 <std::__1::basic_ios<char, std::__1::char_traits<char>>::setstate[abi:ue170006](unsigned int)>:
;     _LIBCPP_INLINE_VISIBILITY void setstate(iostate __state) {ios_base::setstate(__state);}
100001860: 55                          	pushq	%rbp
100001861: 48 89 e5                    	movq	%rsp, %rbp
100001864: 48 83 ec 10                 	subq	$16, %rsp
100001868: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
10000186c: 89 75 f4                    	movl	%esi, -12(%rbp)
10000186f: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001873: 8b 75 f4                    	movl	-12(%rbp), %esi
100001876: e8 35 05 00 00              	callq	0x100001db0 <std::__1::ios_base::setstate[abi:ue170006](unsigned int)>
10000187b: 48 83 c4 10                 	addq	$16, %rsp
10000187f: 5d                          	popq	%rbp
100001880: c3                          	retq
100001881: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000188b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001890 <___clang_call_terminate>:
100001890: 50                          	pushq	%rax
100001891: e8 b3 05 00 00              	callq	0x100001e49 <_strlen+0x100001e49>
100001896: e8 a8 05 00 00              	callq	0x100001e43 <_strlen+0x100001e43>
10000189b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

00000001000018a0 <std::__1::ios_base::width[abi:ue170006]() const>:
; {
1000018a0: 55                          	pushq	%rbp
1000018a1: 48 89 e5                    	movq	%rsp, %rbp
1000018a4: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
1000018a8: 48 8b 45 f8                 	movq	-8(%rbp), %rax
;     return __width_;
1000018ac: 48 8b 40 18                 	movq	24(%rax), %rax
1000018b0: 5d                          	popq	%rbp
1000018b1: c3                          	retq
1000018b2: 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00   	nopw	%cs:(%rax,%rax)

00000001000018c0 <std::__1::basic_streambuf<char, std::__1::char_traits<char>>::sputn[abi:ue170006](char const*, long)>:
;     { return xsputn(__s, __n); }
1000018c0: 55                          	pushq	%rbp
1000018c1: 48 89 e5                    	movq	%rsp, %rbp
1000018c4: 48 83 ec 20                 	subq	$32, %rsp
1000018c8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
1000018cc: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
1000018d0: 48 89 55 e8                 	movq	%rdx, -24(%rbp)
1000018d4: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
1000018d8: 48 8b 75 f0                 	movq	-16(%rbp), %rsi
1000018dc: 48 8b 55 e8                 	movq	-24(%rbp), %rdx
1000018e0: 48 8b 07                    	movq	(%rdi), %rax
1000018e3: ff 50 60                    	callq	*96(%rax)
1000018e6: 48 83 c4 20                 	addq	$32, %rsp
1000018ea: 5d                          	popq	%rbp
1000018eb: c3                          	retq
1000018ec: 0f 1f 40 00                 	nopl	(%rax)

00000001000018f0 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::basic_string[abi:ue170006](unsigned long, char)>:
;       : __r_(__default_init_tag(), __default_init_tag()) {
1000018f0: 55                          	pushq	%rbp
1000018f1: 48 89 e5                    	movq	%rsp, %rbp
1000018f4: 48 83 ec 20                 	subq	$32, %rsp
1000018f8: 88 d0                       	movb	%dl, %al
1000018fa: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
1000018fe: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
100001902: 88 45 ef                    	movb	%al, -17(%rbp)
100001905: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001909: 48 8b 75 f0                 	movq	-16(%rbp), %rsi
10000190d: 0f be 55 ef                 	movsbl	-17(%rbp), %edx
100001911: e8 6a 00 00 00              	callq	0x100001980 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::basic_string[abi:ue170006](unsigned long, char)>
;   }
100001916: 48 83 c4 20                 	addq	$32, %rsp
10000191a: 5d                          	popq	%rbp
10000191b: c3                          	retq
10000191c: 0f 1f 40 00                 	nopl	(%rax)

0000000100001920 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::data[abi:ue170006]() const>:
;     const value_type* data() const _NOEXCEPT  {return std::__to_address(__get_pointer());}
100001920: 55                          	pushq	%rbp
100001921: 48 89 e5                    	movq	%rsp, %rbp
100001924: 48 83 ec 10                 	subq	$16, %rsp
100001928: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
10000192c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001930: e8 6b 01 00 00              	callq	0x100001aa0 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_pointer[abi:ue170006]() const>
100001935: 48 89 c7                    	movq	%rax, %rdi
100001938: e8 53 01 00 00              	callq	0x100001a90 <char const* std::__1::__to_address[abi:ue170006]<char const>(char const*)>
10000193d: 48 83 c4 10                 	addq	$16, %rsp
100001941: 5d                          	popq	%rbp
100001942: c3                          	retq
100001943: 66 66 66 66 2e 0f 1f 84 00 00 00 00 00      	nopw	%cs:(%rax,%rax)

0000000100001950 <std::__1::ios_base::width[abi:ue170006](long)>:
; {
100001950: 55                          	pushq	%rbp
100001951: 48 89 e5                    	movq	%rsp, %rbp
100001954: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001958: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
10000195c: 48 8b 45 f8                 	movq	-8(%rbp), %rax
;     streamsize __r = __width_;
100001960: 48 8b 48 18                 	movq	24(%rax), %rcx
100001964: 48 89 4d e8                 	movq	%rcx, -24(%rbp)
;     __width_ = __wide;
100001968: 48 8b 4d f0                 	movq	-16(%rbp), %rcx
10000196c: 48 89 48 18                 	movq	%rcx, 24(%rax)
;     return __r;
100001970: 48 8b 45 e8                 	movq	-24(%rbp), %rax
100001974: 5d                          	popq	%rbp
100001975: c3                          	retq
100001976: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)

0000000100001980 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::basic_string[abi:ue170006](unsigned long, char)>:
;       : __r_(__default_init_tag(), __default_init_tag()) {
100001980: 55                          	pushq	%rbp
100001981: 48 89 e5                    	movq	%rsp, %rbp
100001984: 48 83 ec 30                 	subq	$48, %rsp
100001988: 88 d0                       	movb	%dl, %al
10000198a: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
10000198e: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
100001992: 88 45 ef                    	movb	%al, -17(%rbp)
100001995: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001999: 48 89 7d d8                 	movq	%rdi, -40(%rbp)
10000199d: 48 8d 75 e8                 	leaq	-24(%rbp), %rsi
1000019a1: 48 8d 55 e0                 	leaq	-32(%rbp), %rdx
1000019a5: e8 26 00 00 00              	callq	0x1000019d0 <std::__1::__compressed_pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, std::__1::allocator<char>>::__compressed_pair[abi:ue170006]<std::__1::__default_init_tag, std::__1::__default_init_tag>(std::__1::__default_init_tag&&, std::__1::__default_init_tag&&)>
1000019aa: 48 8b 7d d8                 	movq	-40(%rbp), %rdi
;     __init(__n, __c);
1000019ae: 48 8b 75 f0                 	movq	-16(%rbp), %rsi
1000019b2: 0f be 55 ef                 	movsbl	-17(%rbp), %edx
1000019b6: e8 52 04 00 00              	callq	0x100001e0d <_strlen+0x100001e0d>
;   }
1000019bb: 48 83 c4 30                 	addq	$48, %rsp
1000019bf: 5d                          	popq	%rbp
1000019c0: c3                          	retq
1000019c1: 66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00	nopw	%cs:(%rax,%rax)

00000001000019d0 <std::__1::__compressed_pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, std::__1::allocator<char>>::__compressed_pair[abi:ue170006]<std::__1::__default_init_tag, std::__1::__default_init_tag>(std::__1::__default_init_tag&&, std::__1::__default_init_tag&&)>:
;   explicit __compressed_pair(_U1&& __t1, _U2&& __t2) : _Base1(std::forward<_U1>(__t1)), _Base2(std::forward<_U2>(__t2)) {}
1000019d0: 55                          	pushq	%rbp
1000019d1: 48 89 e5                    	movq	%rsp, %rbp
1000019d4: 48 83 ec 20                 	subq	$32, %rsp
1000019d8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
1000019dc: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
1000019e0: 48 89 55 e8                 	movq	%rdx, -24(%rbp)
1000019e4: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
1000019e8: 48 8b 75 f0                 	movq	-16(%rbp), %rsi
1000019ec: 48 8b 55 e8                 	movq	-24(%rbp), %rdx
1000019f0: e8 0b 00 00 00              	callq	0x100001a00 <std::__1::__compressed_pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, std::__1::allocator<char>>::__compressed_pair[abi:ue170006]<std::__1::__default_init_tag, std::__1::__default_init_tag>(std::__1::__default_init_tag&&, std::__1::__default_init_tag&&)>
1000019f5: 48 83 c4 20                 	addq	$32, %rsp
1000019f9: 5d                          	popq	%rbp
1000019fa: c3                          	retq
1000019fb: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001a00 <std::__1::__compressed_pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, std::__1::allocator<char>>::__compressed_pair[abi:ue170006]<std::__1::__default_init_tag, std::__1::__default_init_tag>(std::__1::__default_init_tag&&, std::__1::__default_init_tag&&)>:
;   explicit __compressed_pair(_U1&& __t1, _U2&& __t2) : _Base1(std::forward<_U1>(__t1)), _Base2(std::forward<_U2>(__t2)) {}
100001a00: 55                          	pushq	%rbp
100001a01: 48 89 e5                    	movq	%rsp, %rbp
100001a04: 48 83 ec 30                 	subq	$48, %rsp
100001a08: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001a0c: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
100001a10: 48 89 55 e8                 	movq	%rdx, -24(%rbp)
100001a14: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001a18: 48 89 7d d0                 	movq	%rdi, -48(%rbp)
100001a1c: e8 0f 00 00 00              	callq	0x100001a30 <std::__1::__compressed_pair_elem<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, 0, false>::__compressed_pair_elem[abi:ue170006](std::__1::__default_init_tag)>
100001a21: 48 8b 7d d0                 	movq	-48(%rbp), %rdi
100001a25: e8 16 00 00 00              	callq	0x100001a40 <std::__1::__compressed_pair_elem<std::__1::allocator<char>, 1, true>::__compressed_pair_elem[abi:ue170006](std::__1::__default_init_tag)>
100001a2a: 48 83 c4 30                 	addq	$48, %rsp
100001a2e: 5d                          	popq	%rbp
100001a2f: c3                          	retq

0000000100001a30 <std::__1::__compressed_pair_elem<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, 0, false>::__compressed_pair_elem[abi:ue170006](std::__1::__default_init_tag)>:
;   _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR explicit __compressed_pair_elem(__default_init_tag) {}
100001a30: 55                          	pushq	%rbp
100001a31: 48 89 e5                    	movq	%rsp, %rbp
100001a34: 48 89 7d f0                 	movq	%rdi, -16(%rbp)
100001a38: 5d                          	popq	%rbp
100001a39: c3                          	retq
100001a3a: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)

0000000100001a40 <std::__1::__compressed_pair_elem<std::__1::allocator<char>, 1, true>::__compressed_pair_elem[abi:ue170006](std::__1::__default_init_tag)>:
;   _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR explicit __compressed_pair_elem(__default_init_tag) {}
100001a40: 55                          	pushq	%rbp
100001a41: 48 89 e5                    	movq	%rsp, %rbp
100001a44: 48 83 ec 10                 	subq	$16, %rsp
100001a48: 48 89 7d f0                 	movq	%rdi, -16(%rbp)
100001a4c: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
100001a50: e8 0b 00 00 00              	callq	0x100001a60 <std::__1::allocator<char>::allocator[abi:ue170006]()>
100001a55: 48 83 c4 10                 	addq	$16, %rsp
100001a59: 5d                          	popq	%rbp
100001a5a: c3                          	retq
100001a5b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001a60 <std::__1::allocator<char>::allocator[abi:ue170006]()>:
;     _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 allocator() _NOEXCEPT = default;
100001a60: 55                          	pushq	%rbp
100001a61: 48 89 e5                    	movq	%rsp, %rbp
100001a64: 48 83 ec 10                 	subq	$16, %rsp
100001a68: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001a6c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001a70: e8 0b 00 00 00              	callq	0x100001a80 <std::__1::__non_trivial_if<true, std::__1::allocator<char>>::__non_trivial_if[abi:ue170006]()>
100001a75: 48 83 c4 10                 	addq	$16, %rsp
100001a79: 5d                          	popq	%rbp
100001a7a: c3                          	retq
100001a7b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001a80 <std::__1::__non_trivial_if<true, std::__1::allocator<char>>::__non_trivial_if[abi:ue170006]()>:
;     _LIBCPP_CONSTEXPR __non_trivial_if() _NOEXCEPT { }
100001a80: 55                          	pushq	%rbp
100001a81: 48 89 e5                    	movq	%rsp, %rbp
100001a84: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001a88: 5d                          	popq	%rbp
100001a89: c3                          	retq
100001a8a: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)

0000000100001a90 <char const* std::__1::__to_address[abi:ue170006]<char const>(char const*)>:
; _Tp* __to_address(_Tp* __p) _NOEXCEPT {
100001a90: 55                          	pushq	%rbp
100001a91: 48 89 e5                    	movq	%rsp, %rbp
100001a94: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
;     return __p;
100001a98: 48 8b 45 f8                 	movq	-8(%rbp), %rax
100001a9c: 5d                          	popq	%rbp
100001a9d: c3                          	retq
100001a9e: 66 90                       	nop

0000000100001aa0 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_pointer[abi:ue170006]() const>:
;         {return __is_long() ? __get_long_pointer() : __get_short_pointer();}
100001aa0: 55                          	pushq	%rbp
100001aa1: 48 89 e5                    	movq	%rsp, %rbp
100001aa4: 48 83 ec 20                 	subq	$32, %rsp
100001aa8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001aac: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001ab0: 48 89 7d f0                 	movq	%rdi, -16(%rbp)
100001ab4: e8 37 00 00 00              	callq	0x100001af0 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ue170006]() const>
100001ab9: a8 01                       	testb	$1, %al
100001abb: 0f 85 05 00 00 00           	jne	0x100001ac6 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_pointer[abi:ue170006]() const+0x26>
100001ac1: e9 12 00 00 00              	jmp	0x100001ad8 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_pointer[abi:ue170006]() const+0x38>
100001ac6: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
;         {return __is_long() ? __get_long_pointer() : __get_short_pointer();}
100001aca: e8 81 00 00 00              	callq	0x100001b50 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_long_pointer[abi:ue170006]() const>
100001acf: 48 89 45 e8                 	movq	%rax, -24(%rbp)
100001ad3: e9 0d 00 00 00              	jmp	0x100001ae5 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_pointer[abi:ue170006]() const+0x45>
100001ad8: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
;         {return __is_long() ? __get_long_pointer() : __get_short_pointer();}
100001adc: e8 8f 00 00 00              	callq	0x100001b70 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_short_pointer[abi:ue170006]() const>
100001ae1: 48 89 45 e8                 	movq	%rax, -24(%rbp)
100001ae5: 48 8b 45 e8                 	movq	-24(%rbp), %rax
;         {return __is_long() ? __get_long_pointer() : __get_short_pointer();}
100001ae9: 48 83 c4 20                 	addq	$32, %rsp
100001aed: 5d                          	popq	%rbp
100001aee: c3                          	retq
100001aef: 90                          	nop

0000000100001af0 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ue170006]() const>:
;     bool __is_long() const _NOEXCEPT {
100001af0: 55                          	pushq	%rbp
100001af1: 48 89 e5                    	movq	%rsp, %rbp
100001af4: 48 83 ec 20                 	subq	$32, %rsp
100001af8: 48 89 7d f0                 	movq	%rdi, -16(%rbp)
100001afc: 48 8b 45 f0                 	movq	-16(%rbp), %rax
100001b00: 48 89 45 e8                 	movq	%rax, -24(%rbp)
;         if (__libcpp_is_constant_evaluated())
100001b04: e8 97 00 00 00              	callq	0x100001ba0 <std::__1::__libcpp_is_constant_evaluated[abi:ue170006]()>
100001b09: a8 01                       	testb	$1, %al
100001b0b: 0f 85 05 00 00 00           	jne	0x100001b16 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ue170006]() const+0x26>
100001b11: e9 09 00 00 00              	jmp	0x100001b1f <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ue170006]() const+0x2f>
;             return true;
100001b16: c6 45 ff 01                 	movb	$1, -1(%rbp)
100001b1a: e9 17 00 00 00              	jmp	0x100001b36 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ue170006]() const+0x46>
100001b1f: 48 8b 7d e8                 	movq	-24(%rbp), %rdi
;         return __r_.first().__s.__is_long_;
100001b23: e8 88 00 00 00              	callq	0x100001bb0 <std::__1::__compressed_pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, std::__1::allocator<char>>::first[abi:ue170006]() const>
100001b28: 8a 00                       	movb	(%rax), %al
100001b2a: 24 01                       	andb	$1, %al
100001b2c: 3c 00                       	cmpb	$0, %al
100001b2e: 0f 95 c0                    	setne	%al
100001b31: 24 01                       	andb	$1, %al
100001b33: 88 45 ff                    	movb	%al, -1(%rbp)
;     }
100001b36: 8a 45 ff                    	movb	-1(%rbp), %al
100001b39: 24 01                       	andb	$1, %al
100001b3b: 0f b6 c0                    	movzbl	%al, %eax
100001b3e: 48 83 c4 20                 	addq	$32, %rsp
100001b42: 5d                          	popq	%rbp
100001b43: c3                          	retq
100001b44: 66 66 66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)

0000000100001b50 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_long_pointer[abi:ue170006]() const>:
;         {return __r_.first().__l.__data_;}
100001b50: 55                          	pushq	%rbp
100001b51: 48 89 e5                    	movq	%rsp, %rbp
100001b54: 48 83 ec 10                 	subq	$16, %rsp
100001b58: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001b5c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001b60: e8 4b 00 00 00              	callq	0x100001bb0 <std::__1::__compressed_pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, std::__1::allocator<char>>::first[abi:ue170006]() const>
100001b65: 48 8b 40 10                 	movq	16(%rax), %rax
100001b69: 48 83 c4 10                 	addq	$16, %rsp
100001b6d: 5d                          	popq	%rbp
100001b6e: c3                          	retq
100001b6f: 90                          	nop

0000000100001b70 <std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_short_pointer[abi:ue170006]() const>:
;         {return pointer_traits<const_pointer>::pointer_to(__r_.first().__s.__data_[0]);}
100001b70: 55                          	pushq	%rbp
100001b71: 48 89 e5                    	movq	%rsp, %rbp
100001b74: 48 83 ec 10                 	subq	$16, %rsp
100001b78: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001b7c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001b80: e8 2b 00 00 00              	callq	0x100001bb0 <std::__1::__compressed_pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, std::__1::allocator<char>>::first[abi:ue170006]() const>
100001b85: 48 89 c7                    	movq	%rax, %rdi
100001b88: 48 83 c7 01                 	addq	$1, %rdi
100001b8c: e8 4f 00 00 00              	callq	0x100001be0 <std::__1::pointer_traits<char const*>::pointer_to[abi:ue170006](char const&)>
100001b91: 48 83 c4 10                 	addq	$16, %rsp
100001b95: 5d                          	popq	%rbp
100001b96: c3                          	retq
100001b97: 66 0f 1f 84 00 00 00 00 00  	nopw	(%rax,%rax)

0000000100001ba0 <std::__1::__libcpp_is_constant_evaluated[abi:ue170006]()>:
; _LIBCPP_HIDE_FROM_ABI inline _LIBCPP_CONSTEXPR bool __libcpp_is_constant_evaluated() _NOEXCEPT {
100001ba0: 55                          	pushq	%rbp
100001ba1: 48 89 e5                    	movq	%rsp, %rbp
;   return __builtin_is_constant_evaluated();
100001ba4: 31 c0                       	xorl	%eax, %eax
100001ba6: 24 01                       	andb	$1, %al
100001ba8: 0f b6 c0                    	movzbl	%al, %eax
100001bab: 5d                          	popq	%rbp
100001bac: c3                          	retq
100001bad: 0f 1f 00                    	nopl	(%rax)

0000000100001bb0 <std::__1::__compressed_pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, std::__1::allocator<char>>::first[abi:ue170006]() const>:
;   typename _Base1::const_reference first() const _NOEXCEPT {
100001bb0: 55                          	pushq	%rbp
100001bb1: 48 89 e5                    	movq	%rsp, %rbp
100001bb4: 48 83 ec 10                 	subq	$16, %rsp
100001bb8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001bbc: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
;     return static_cast<_Base1 const&>(*this).__get();
100001bc0: e8 0b 00 00 00              	callq	0x100001bd0 <std::__1::__compressed_pair_elem<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, 0, false>::__get[abi:ue170006]() const>
100001bc5: 48 83 c4 10                 	addq	$16, %rsp
100001bc9: 5d                          	popq	%rbp
100001bca: c3                          	retq
100001bcb: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001bd0 <std::__1::__compressed_pair_elem<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__rep, 0, false>::__get[abi:ue170006]() const>:
;   _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR const_reference __get() const _NOEXCEPT { return __value_; }
100001bd0: 55                          	pushq	%rbp
100001bd1: 48 89 e5                    	movq	%rsp, %rbp
100001bd4: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001bd8: 48 8b 45 f8                 	movq	-8(%rbp), %rax
100001bdc: 5d                          	popq	%rbp
100001bdd: c3                          	retq
100001bde: 66 90                       	nop

0000000100001be0 <std::__1::pointer_traits<char const*>::pointer_to[abi:ue170006](char const&)>:
;         {return _VSTD::addressof(__r);}
100001be0: 55                          	pushq	%rbp
100001be1: 48 89 e5                    	movq	%rsp, %rbp
100001be4: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001be8: 48 8b 45 f8                 	movq	-8(%rbp), %rax
100001bec: 5d                          	popq	%rbp
100001bed: c3                          	retq
100001bee: 66 90                       	nop

0000000100001bf0 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>::ostreambuf_iterator[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>&)>:
;         : __sbuf_(__s.rdbuf()) {}
100001bf0: 55                          	pushq	%rbp
100001bf1: 48 89 e5                    	movq	%rsp, %rbp
100001bf4: 48 83 ec 30                 	subq	$48, %rsp
100001bf8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001bfc: 48 89 75 f0                 	movq	%rsi, -16(%rbp)
100001c00: 48 8b 45 f8                 	movq	-8(%rbp), %rax
100001c04: 48 89 45 d0                 	movq	%rax, -48(%rbp)
100001c08: 48 8b 7d f0                 	movq	-16(%rbp), %rdi
100001c0c: 48 8b 07                    	movq	(%rdi), %rax
100001c0f: 48 8b 40 e8                 	movq	-24(%rax), %rax
100001c13: 48 01 c7                    	addq	%rax, %rdi
100001c16: e8 35 00 00 00              	callq	0x100001c50 <std::__1::basic_ios<char, std::__1::char_traits<char>>::rdbuf[abi:ue170006]() const>
100001c1b: 48 89 45 d8                 	movq	%rax, -40(%rbp)
100001c1f: e9 00 00 00 00              	jmp	0x100001c24 <std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>::ostreambuf_iterator[abi:ue170006](std::__1::basic_ostream<char, std::__1::char_traits<char>>&)+0x34>
100001c24: 48 8b 45 d0                 	movq	-48(%rbp), %rax
100001c28: 48 8b 4d d8                 	movq	-40(%rbp), %rcx
;         : __sbuf_(__s.rdbuf()) {}
100001c2c: 48 89 08                    	movq	%rcx, (%rax)
100001c2f: 48 83 c4 30                 	addq	$48, %rsp
100001c33: 5d                          	popq	%rbp
100001c34: c3                          	retq
100001c35: 48 89 c1                    	movq	%rax, %rcx
;         : __sbuf_(__s.rdbuf()) {}
100001c38: 89 d0                       	movl	%edx, %eax
100001c3a: 48 89 4d e8                 	movq	%rcx, -24(%rbp)
100001c3e: 89 45 e4                    	movl	%eax, -28(%rbp)
100001c41: 48 8b 7d e8                 	movq	-24(%rbp), %rdi
100001c45: e8 05 02 00 00              	callq	0x100001e4f <_strlen+0x100001e4f>
100001c4a: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)

0000000100001c50 <std::__1::basic_ios<char, std::__1::char_traits<char>>::rdbuf[abi:ue170006]() const>:
; {
100001c50: 55                          	pushq	%rbp
100001c51: 48 89 e5                    	movq	%rsp, %rbp
100001c54: 48 83 ec 10                 	subq	$16, %rsp
100001c58: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001c5c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
;     return static_cast<basic_streambuf<char_type, traits_type>*>(ios_base::rdbuf());
100001c60: e8 0b 00 00 00              	callq	0x100001c70 <std::__1::ios_base::rdbuf[abi:ue170006]() const>
100001c65: 48 83 c4 10                 	addq	$16, %rsp
100001c69: 5d                          	popq	%rbp
100001c6a: c3                          	retq
100001c6b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001c70 <std::__1::ios_base::rdbuf[abi:ue170006]() const>:
;     _LIBCPP_INLINE_VISIBILITY void* rdbuf() const {return __rdbuf_;}
100001c70: 55                          	pushq	%rbp
100001c71: 48 89 e5                    	movq	%rsp, %rbp
100001c74: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001c78: 48 8b 45 f8                 	movq	-8(%rbp), %rax
100001c7c: 48 8b 40 28                 	movq	40(%rax), %rax
100001c80: 5d                          	popq	%rbp
100001c81: c3                          	retq
100001c82: 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00   	nopw	%cs:(%rax,%rax)

0000000100001c90 <std::__1::char_traits<char>::eq_int_type[abi:ue170006](int, int)>:
;         {return __c1 == __c2;}
100001c90: 55                          	pushq	%rbp
100001c91: 48 89 e5                    	movq	%rsp, %rbp
100001c94: 89 7d fc                    	movl	%edi, -4(%rbp)
100001c97: 89 75 f8                    	movl	%esi, -8(%rbp)
100001c9a: 8b 45 fc                    	movl	-4(%rbp), %eax
100001c9d: 3b 45 f8                    	cmpl	-8(%rbp), %eax
100001ca0: 0f 94 c0                    	sete	%al
100001ca3: 24 01                       	andb	$1, %al
100001ca5: 0f b6 c0                    	movzbl	%al, %eax
100001ca8: 5d                          	popq	%rbp
100001ca9: c3                          	retq
100001caa: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)

0000000100001cb0 <std::__1::char_traits<char>::eof[abi:ue170006]()>:
;         {return int_type(EOF);}
100001cb0: 55                          	pushq	%rbp
100001cb1: 48 89 e5                    	movq	%rsp, %rbp
100001cb4: b8 ff ff ff ff              	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
100001cb9: 5d                          	popq	%rbp
100001cba: c3                          	retq
100001cbb: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001cc0 <std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:ue170006](char) const>:
; {
100001cc0: 55                          	pushq	%rbp
100001cc1: 48 89 e5                    	movq	%rsp, %rbp
100001cc4: 48 83 ec 40                 	subq	$64, %rsp
100001cc8: 40 88 f0                    	movb	%sil, %al
100001ccb: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001ccf: 88 45 f7                    	movb	%al, -9(%rbp)
100001cd2: 48 8b 75 f8                 	movq	-8(%rbp), %rsi
100001cd6: 48 8d 7d e8                 	leaq	-24(%rbp), %rdi
100001cda: 48 89 7d c8                 	movq	%rdi, -56(%rbp)
;     return std::use_facet<ctype<char_type> >(getloc()).widen(__c);
100001cde: e8 24 01 00 00              	callq	0x100001e07 <_strlen+0x100001e07>
100001ce3: 48 8b 7d c8                 	movq	-56(%rbp), %rdi
100001ce7: e8 64 00 00 00              	callq	0x100001d50 <std::__1::ctype<char> const& std::__1::use_facet[abi:ue170006]<std::__1::ctype<char>>(std::__1::locale const&)>
100001cec: 48 89 45 d0                 	movq	%rax, -48(%rbp)
100001cf0: e9 00 00 00 00              	jmp	0x100001cf5 <std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:ue170006](char) const+0x35>
100001cf5: 48 8b 7d d0                 	movq	-48(%rbp), %rdi
;     return std::use_facet<ctype<char_type> >(getloc()).widen(__c);
100001cf9: 0f be 75 f7                 	movsbl	-9(%rbp), %esi
100001cfd: e8 7e 00 00 00              	callq	0x100001d80 <std::__1::ctype<char>::widen[abi:ue170006](char) const>
100001d02: 88 45 c7                    	movb	%al, -57(%rbp)
100001d05: e9 00 00 00 00              	jmp	0x100001d0a <std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:ue170006](char) const+0x4a>
100001d0a: 48 8d 7d e8                 	leaq	-24(%rbp), %rdi
100001d0e: e8 1e 01 00 00              	callq	0x100001e31 <_strlen+0x100001e31>
100001d13: 8a 45 c7                    	movb	-57(%rbp), %al
100001d16: 0f be c0                    	movsbl	%al, %eax
100001d19: 48 83 c4 40                 	addq	$64, %rsp
100001d1d: 5d                          	popq	%rbp
100001d1e: c3                          	retq
100001d1f: 48 89 c1                    	movq	%rax, %rcx
; }
100001d22: 89 d0                       	movl	%edx, %eax
100001d24: 48 89 4d e0                 	movq	%rcx, -32(%rbp)
100001d28: 89 45 dc                    	movl	%eax, -36(%rbp)
100001d2b: 48 8d 7d e8                 	leaq	-24(%rbp), %rdi
;     return std::use_facet<ctype<char_type> >(getloc()).widen(__c);
100001d2f: e8 fd 00 00 00              	callq	0x100001e31 <_strlen+0x100001e31>
100001d34: e9 00 00 00 00              	jmp	0x100001d39 <std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:ue170006](char) const+0x79>
100001d39: e9 00 00 00 00              	jmp	0x100001d3e <std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:ue170006](char) const+0x7e>
100001d3e: 48 8b 7d e0                 	movq	-32(%rbp), %rdi
100001d42: e8 b4 00 00 00              	callq	0x100001dfb <_strlen+0x100001dfb>
100001d47: 48 89 c7                    	movq	%rax, %rdi
;     return std::use_facet<ctype<char_type> >(getloc()).widen(__c);
100001d4a: e8 41 fb ff ff              	callq	0x100001890 <___clang_call_terminate>
100001d4f: 90                          	nop

0000000100001d50 <std::__1::ctype<char> const& std::__1::use_facet[abi:ue170006]<std::__1::ctype<char>>(std::__1::locale const&)>:
; {
100001d50: 55                          	pushq	%rbp
100001d51: 48 89 e5                    	movq	%rsp, %rbp
100001d54: 48 83 ec 10                 	subq	$16, %rsp
100001d58: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
;     return static_cast<const _Facet&>(*__l.use_facet(_Facet::id));
100001d5c: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001d60: 48 8b 35 e9 02 00 00        	movq	745(%rip), %rsi         ## 0x100002050 <_strlen+0x100002050>
100001d67: e8 95 00 00 00              	callq	0x100001e01 <_strlen+0x100001e01>
100001d6c: 48 83 c4 10                 	addq	$16, %rsp
100001d70: 5d                          	popq	%rbp
100001d71: c3                          	retq
100001d72: 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00   	nopw	%cs:(%rax,%rax)

0000000100001d80 <std::__1::ctype<char>::widen[abi:ue170006](char) const>:
;     {
100001d80: 55                          	pushq	%rbp
100001d81: 48 89 e5                    	movq	%rsp, %rbp
100001d84: 48 83 ec 10                 	subq	$16, %rsp
100001d88: 40 88 f0                    	movb	%sil, %al
100001d8b: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001d8f: 88 45 f7                    	movb	%al, -9(%rbp)
100001d92: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
;         return do_widen(__c);
100001d96: 8a 4d f7                    	movb	-9(%rbp), %cl
100001d99: 48 8b 07                    	movq	(%rdi), %rax
100001d9c: 0f be f1                    	movsbl	%cl, %esi
100001d9f: ff 50 38                    	callq	*56(%rax)
100001da2: 0f be c0                    	movsbl	%al, %eax
100001da5: 48 83 c4 10                 	addq	$16, %rsp
100001da9: 5d                          	popq	%rbp
100001daa: c3                          	retq
100001dab: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100001db0 <std::__1::ios_base::setstate[abi:ue170006](unsigned int)>:
; {
100001db0: 55                          	pushq	%rbp
100001db1: 48 89 e5                    	movq	%rsp, %rbp
100001db4: 48 83 ec 10                 	subq	$16, %rsp
100001db8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
100001dbc: 89 75 f4                    	movl	%esi, -12(%rbp)
100001dbf: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
;     clear(__rdstate_ | __state);
100001dc3: 8b 77 20                    	movl	32(%rdi), %esi
100001dc6: 0b 75 f4                    	orl	-12(%rbp), %esi
100001dc9: e8 6f 00 00 00              	callq	0x100001e3d <_strlen+0x100001e3d>
; }
100001dce: 48 83 c4 10                 	addq	$16, %rsp
100001dd2: 5d                          	popq	%rbp
100001dd3: c3                          	retq
100001dd4: 66 66 66 2e 0f 1f 84 00 00 00 00 00 	nopw	%cs:(%rax,%rax)

0000000100001de0 <std::__1::__constexpr_strlen[abi:ue170006](char const*)>:
; inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX14 size_t __constexpr_strlen(const char* __str) {
100001de0: 55                          	pushq	%rbp
100001de1: 48 89 e5                    	movq	%rsp, %rbp
100001de4: 48 83 ec 10                 	subq	$16, %rsp
100001de8: 48 89 7d f8                 	movq	%rdi, -8(%rbp)
;   return __builtin_strlen(__str);
100001dec: 48 8b 7d f8                 	movq	-8(%rbp), %rdi
100001df0: e8 66 00 00 00              	callq	0x100001e5b <_strlen+0x100001e5b>
100001df5: 48 83 c4 10                 	addq	$16, %rsp
100001df9: 5d                          	popq	%rbp
100001dfa: c3                          	retq

Disassembly of section __TEXT,__stubs:

0000000100001dfb <__stubs>:
100001dfb: ff 25 ff 01 00 00           	jmpq	*511(%rip)              ## 0x100002000 <_strlen+0x100002000>
100001e01: ff 25 01 02 00 00           	jmpq	*513(%rip)              ## 0x100002008 <_strlen+0x100002008>
100001e07: ff 25 03 02 00 00           	jmpq	*515(%rip)              ## 0x100002010 <_strlen+0x100002010>
100001e0d: ff 25 05 02 00 00           	jmpq	*517(%rip)              ## 0x100002018 <_strlen+0x100002018>
100001e13: ff 25 07 02 00 00           	jmpq	*519(%rip)              ## 0x100002020 <_strlen+0x100002020>
100001e19: ff 25 09 02 00 00           	jmpq	*521(%rip)              ## 0x100002028 <_strlen+0x100002028>
100001e1f: ff 25 0b 02 00 00           	jmpq	*523(%rip)              ## 0x100002030 <_strlen+0x100002030>
100001e25: ff 25 0d 02 00 00           	jmpq	*525(%rip)              ## 0x100002038 <_strlen+0x100002038>
100001e2b: ff 25 0f 02 00 00           	jmpq	*527(%rip)              ## 0x100002040 <_strlen+0x100002040>
100001e31: ff 25 21 02 00 00           	jmpq	*545(%rip)              ## 0x100002058 <_strlen+0x100002058>
100001e37: ff 25 23 02 00 00           	jmpq	*547(%rip)              ## 0x100002060 <_strlen+0x100002060>
100001e3d: ff 25 25 02 00 00           	jmpq	*549(%rip)              ## 0x100002068 <_strlen+0x100002068>
100001e43: ff 25 27 02 00 00           	jmpq	*551(%rip)              ## 0x100002070 <_strlen+0x100002070>
100001e49: ff 25 29 02 00 00           	jmpq	*553(%rip)              ## 0x100002078 <_strlen+0x100002078>
100001e4f: ff 25 2b 02 00 00           	jmpq	*555(%rip)              ## 0x100002080 <_strlen+0x100002080>
100001e55: ff 25 2d 02 00 00           	jmpq	*557(%rip)              ## 0x100002088 <_strlen+0x100002088>
100001e5b: ff 25 37 02 00 00           	jmpq	*567(%rip)              ## 0x100002098 <_strlen+0x100002098>

Disassembly of section __TEXT,__gcc_except_tab:

0000000100001e64 <GCC_except_table10>:
100001e64: ff 9b 3d 01 32 1b           	lcalll	*456261949(%rbx)
100001e6a: 09 c9                       	orl	%ecx, %ecx
100001e6c: 02 01                       	addb	(%rcx), %al
100001e6e: 29 96 02 da 02 01           	subl	%edx, 16964098(%rsi)
100001e74: e6 02                       	outb	%al, $2
100001e76: 09 e8                       	orl	%ebp, %eax
100001e78: 03 01                       	addl	(%rcx), %eax
100001e7a: f9                          	stc
100001e7b: 02 09                       	addb	(%rcx), %cl
100001e7d: c9                          	leave
100001e7e: 02 01                       	addb	(%rcx), %al
100001e80: 82                          	<unknown>
100001e81: 03 26                       	addl	(%rsi), %esp
100001e83: 00 00                       	addb	%al, (%rax)
100001e85: a8 03                       	testb	$3, %al
100001e87: 05 c4 03 00 ad              	addl	$2902459332, %eax       ## imm = 0xAD0003C4
100001e8c: 03 23                       	addl	(%rbx), %esp
100001e8e: 00 00                       	addb	%al, (%rax)
100001e90: d0 03                       	rolb	(%rbx)
100001e92: 05 e8 03 01 d5              	addl	$3573613544, %eax       ## imm = 0xD50103E8
100001e97: 03 1b                       	addl	(%rbx), %ebx
100001e99: 00 00                       	addb	%al, (%rax)
100001e9b: 01 00                       	addl	%eax, (%rax)
100001e9d: 00 00                       	addb	%al, (%rax)
100001e9f: 00 00                       	addb	%al, (%rax)
100001ea1: 00 00                       	addb	%al, (%rax)
100001ea3: 00 ff                       	addb	%bh, %bh

0000000100001ea4 <GCC_except_table11>:
100001ea4: ff 9b 0d 01 08 10           	lcalll	*268960013(%rbx)
100001eaa: 05 28 01 15 28              	addl	$672465192, %eax        ## imm = 0x28150128
100001eaf: 00 00                       	addb	%al, (%rax)
100001eb1: 7f 00                       	jg	0x100001eb3 <GCC_except_table11+0xf>
100001eb3: 00 00                       	addb	%al, (%rax)
100001eb5: 00 00                       	addb	%al, (%rax)
100001eb7: 00 ff                       	addb	%bh, %bh

0000000100001eb8 <GCC_except_table13>:
100001eb8: ff 9b 21 01 17 00           	lcalll	*1507617(%rbx)
100001ebe: 9a                          	<unknown>
100001ebf: 02 00                       	addb	(%rax), %al
100001ec1: 00 9a 02 05 d2 02           	addb	%bl, 47318274(%rdx)
100001ec7: 00 de                       	addb	%bl, %dh
100001ec9: 02 09                       	addb	(%rcx), %cl
100001ecb: 95                          	xchgl	%ebp, %eax
100001ecc: 04 01                       	addb	$1, %al
100001ece: e7 02                       	outl	%eax, $2
100001ed0: b8 01 00 00 01              	movl	$16777217, %eax         ## imm = 0x1000001
100001ed5: 00 00                       	addb	%al, (%rax)
100001ed7: 00 00                       	addb	%al, (%rax)
100001ed9: 00 00                       	addb	%al, (%rax)
100001edb: 00 ff                       	addb	%bh, %bh

0000000100001edc <GCC_except_table41>:
100001edc: ff 9b 0d 01 08 26           	lcalll	*638058765(%rbx)
100001ee2: 05 45 01 2b 2f              	addl	$791347525, %eax        ## imm = 0x2F2B0145
100001ee7: 00 00                       	addb	%al, (%rax)
100001ee9: 7f 00                       	jg	0x100001eeb <GCC_except_table41+0xf>
100001eeb: 00 00                       	addb	%al, (%rax)
100001eed: 00 00                       	addb	%al, (%rax)
100001eef: 00 ff                       	addb	%bh, %bh

0000000100001ef0 <GCC_except_table46>:
100001ef0: ff 9b 1d 01 15 00           	lcalll	*1376541(%rbx)
100001ef6: 27                          	<unknown>
100001ef7: 00 00                       	addb	%al, (%rax)
100001ef9: 27                          	<unknown>
100001efa: 1b 5f 00                    	sbbl	(%rdi), %ebx
100001efd: 42 29 00                    	subl	%eax, (%rax)
100001f00: 00 6b 09                    	addb	%ch, 9(%rbx)
100001f03: 87 01                       	xchgl	%eax, (%rcx)
100001f05: 01 74 1b 00                 	addl	%esi, (%rbx,%rbx)
100001f09: 00 01                       	addb	%al, (%rcx)
100001f0b: 00 00                       	addb	%al, (%rax)
100001f0d: 00 00                       	addb	%al, (%rax)
100001f0f: 00                          	<unknown>

Disassembly of section __TEXT,__const:

0000000100001f10 <typeinfo name for Der1>:
100001f10: 34 44                       	xorb	$68, %al
100001f12: 65 72 31                    	jb	0x100001f46 <_strlen+0x100001f46>
100001f15: 00 34 42                    	addb	%dh, (%rdx,%rax,2)

0000000100001f16 <typeinfo name for Base>:
100001f16: 34 42                       	xorb	$66, %al
100001f18: 61                          	<unknown>
100001f19: 73 65                       	jae	0x100001f80 <_strlen+0x100001f80>
100001f1b: 00                          	<unknown>

Disassembly of section __TEXT,__cstring:

0000000100001f1c <__cstring>:
100001f1c: 42 61                       	<unknown>
100001f1e: 73 65                       	jae	0x100001f85 <_strlen+0x100001f85>
100001f20: 3a 3a                       	cmpb	(%rdx), %bh
100001f22: 66 31 28                    	xorw	%bp, (%rax)
100001f25: 29 00                       	subl	%eax, (%rax)
100001f27: 42 61                       	<unknown>
100001f29: 73 65                       	jae	0x100001f90 <_strlen+0x100001f90>
100001f2b: 3a 3a                       	cmpb	(%rdx), %bh
100001f2d: 66 32 28                    	xorb	(%rax), %ch
100001f30: 29 00                       	subl	%eax, (%rax)
100001f32: 44 65                       	gs
100001f34: 72 31                       	jb	0x100001f67 <_strlen+0x100001f67>
100001f36: 3a 3a                       	cmpb	(%rdx), %bh
100001f38: 66 31 28                    	xorw	%bp, (%rax)
100001f3b: 29 00                       	subl	%eax, (%rax)

Disassembly of section __TEXT,__unwind_info:

0000000100001f40 <__unwind_info>:
100001f40: 01 00                       	addl	%eax, (%rax)
100001f42: 00 00                       	addb	%al, (%rax)
100001f44: 1c 00                       	sbbb	$0, %al
100001f46: 00 00                       	addb	%al, (%rax)
100001f48: 02 00                       	addb	(%rax), %al
100001f4a: 00 00                       	addb	%al, (%rax)
100001f4c: 24 00                       	andb	$0, %al
100001f4e: 00 00                       	addb	%al, (%rax)
100001f50: 01 00                       	addl	%eax, (%rax)
100001f52: 00 00                       	addb	%al, (%rax)
100001f54: 28 00                       	subb	%al, (%rax)
100001f56: 00 00                       	addb	%al, (%rax)
100001f58: 02 00                       	addb	(%rax), %al
100001f5a: 00 00                       	addb	%al, (%rax)
100001f5c: 00 00                       	addb	%al, (%rax)
100001f5e: 00 01                       	addb	%al, (%rcx)
100001f60: 00 00                       	addb	%al, (%rax)
100001f62: 00 51 90                    	addb	%dl, -112(%rcx)
100001f65: 20 00                       	andb	%al, (%rax)
100001f67: 00 e0                       	addb	%ah, %al
100001f69: 10 00                       	adcb	%al, (%rax)
100001f6b: 00 74 00 00                 	addb	%dh, (%rax,%rax)
100001f6f: 00 4c 00 00                 	addb	%cl, (%rax,%rax)
100001f73: 00 fb                       	addb	%bh, %bl
100001f75: 1d 00 00 00 00              	sbbl	$0, %eax
100001f7a: 00 00                       	addb	%al, (%rax)
100001f7c: 74 00                       	je	0x100001f7e <__unwind_info+0x3e>
		...
100001f8a: 00 00                       	addb	%al, (%rax)
100001f8c: 10 13                       	adcb	%dl, (%rbx)
100001f8e: 00 00                       	addb	%al, (%rax)
100001f90: 64 1e                       	<unknown>
100001f92: 00 00                       	addb	%al, (%rax)
100001f94: 00 15 00 00 a4 1e           	addb	%dl, 514064384(%rip)    ## 0x11ea41f9a <vtable for Base+0x1ea3feb2>
100001f9a: 00 00                       	addb	%al, (%rax)
100001f9c: 60                          	<unknown>
100001f9d: 15 00 00 b8 1e              	adcl	$515375104, %eax        ## imm = 0x1EB80000
100001fa2: 00 00                       	addb	%al, (%rax)
100001fa4: f0                          	lock
100001fa5: 1b 00                       	sbbl	(%rax), %eax
100001fa7: 00 dc                       	addb	%bl, %ah
100001fa9: 1e                          	<unknown>
100001faa: 00 00                       	addb	%al, (%rax)
100001fac: c0 1c 00 00                 	rcrb	$0, (%rax,%rax)
100001fb0: f0                          	lock
100001fb1: 1e                          	<unknown>
100001fb2: 00 00                       	addb	%al, (%rax)
100001fb4: 03 00                       	addl	(%rax), %eax
100001fb6: 00 00                       	addb	%al, (%rax)
100001fb8: 0c 00                       	orb	$0, %al
100001fba: 0c 00                       	orb	$0, %al
100001fbc: 3c 00                       	cmpb	$0, %al
100001fbe: 01 00                       	addl	%eax, (%rax)
100001fc0: 00 00                       	addb	%al, (%rax)
100001fc2: 00 00                       	addb	%al, (%rax)
100001fc4: 30 02                       	xorb	%al, (%rdx)
100001fc6: 00 01                       	addb	%al, (%rcx)
100001fc8: 20 04 00                    	andb	%al, (%rax,%rax)
100001fcb: 01 60 04                    	addl	%esp, 4(%rax)
100001fce: 00 00                       	addb	%al, (%rax)
100001fd0: 80 04 00 01                 	addb	$1, (%rax,%rax)
100001fd4: a0 06 00 00 b0 07 00 02 c0  	movabsb	-4611123035456405498, %al
100001fdd: 07                          	<unknown>
100001fde: 00 00                       	addb	%al, (%rax)
100001fe0: 10 0b                       	adcb	%cl, (%rbx)
100001fe2: 00 01                       	addb	%al, (%rcx)
100001fe4: 70 0b                       	jo	0x100001ff1 <__unwind_info+0xb1>
100001fe6: 00 00                       	addb	%al, (%rax)
100001fe8: e0 0b                       	loopne	0x100001ff5 <__unwind_info+0xb5>
100001fea: 00 01                       	addb	%al, (%rcx)
100001fec: 70 0c                       	jo	0x100001ffa <__unwind_info+0xba>
100001fee: 00 00                       	addb	%al, (%rax)
100001ff0: 00 00                       	addb	%al, (%rax)
100001ff2: 02 02                       	addb	(%rdx), %al
100001ff4: 00 00                       	addb	%al, (%rax)
100001ff6: 00 00                       	addb	%al, (%rax)

Disassembly of section __DATA_CONST,__got:

0000000100002000 <__got>:
100002000: 00 00                       	addb	%al, (%rax)
100002002: 00 00                       	addb	%al, (%rax)
100002004: 00 00                       	addb	%al, (%rax)
100002006: 10 80 01 00 00 00           	adcb	%al, 1(%rax)
10000200c: 00 00                       	addb	%al, (%rax)
10000200e: 10 80 02 00 00 00           	adcb	%al, 2(%rax)
100002014: 00 00                       	addb	%al, (%rax)
100002016: 10 80 03 00 00 00           	adcb	%al, 3(%rax)
10000201c: 00 00                       	addb	%al, (%rax)
10000201e: 10 80 04 00 00 00           	adcb	%al, 4(%rax)
100002024: 00 00                       	addb	%al, (%rax)
100002026: 10 80 05 00 00 00           	adcb	%al, 5(%rax)
10000202c: 00 00                       	addb	%al, (%rax)
10000202e: 10 80 06 00 00 00           	adcb	%al, 6(%rax)
100002034: 00 00                       	addb	%al, (%rax)
100002036: 10 80 07 00 00 00           	adcb	%al, 7(%rax)
10000203c: 00 00                       	addb	%al, (%rax)
10000203e: 10 80 08 00 00 00           	adcb	%al, 8(%rax)
100002044: 00 00                       	addb	%al, (%rax)
100002046: 10 80 09 00 00 00           	adcb	%al, 9(%rax)
10000204c: 00 00                       	addb	%al, (%rax)
10000204e: 10 80 0a 00 00 00           	adcb	%al, 10(%rax)
100002054: 00 00                       	addb	%al, (%rax)
100002056: 10 80 0b 00 00 00           	adcb	%al, 11(%rax)
10000205c: 00 00                       	addb	%al, (%rax)
10000205e: 10 80 0c 00 00 00           	adcb	%al, 12(%rax)
100002064: 00 00                       	addb	%al, (%rax)
100002066: 10 80 0d 00 00 00           	adcb	%al, 13(%rax)
10000206c: 00 00                       	addb	%al, (%rax)
10000206e: 10 80 0e 00 00 00           	adcb	%al, 14(%rax)
100002074: 00 00                       	addb	%al, (%rax)
100002076: 10 80 0f 00 00 00           	adcb	%al, 15(%rax)
10000207c: 00 00                       	addb	%al, (%rax)
10000207e: 10 80 10 00 00 00           	adcb	%al, 16(%rax)
100002084: 00 00                       	addb	%al, (%rax)
100002086: 10 80 11 00 00 00           	adcb	%al, 17(%rax)
10000208c: 00 00                       	addb	%al, (%rax)
10000208e: 10 80 12 00 00 00           	adcb	%al, 18(%rax)
100002094: 00 00                       	addb	%al, (%rax)
100002096: 10 80 13 00 00 00           	adcb	%al, 19(%rax)
10000209c: 00 00                       	addb	%al, (%rax)
10000209e: 20 80                       	<unknown>

Disassembly of section __DATA_CONST,__const:

00000001000020a0 <vtable for Der1>:
		...
1000020a8: 14 00                       	adcb	$0, %al
1000020aa: 00 00                       	addb	%al, (%rax)
1000020ac: 00 00                       	addb	%al, (%rax)
1000020ae: 10 80 40 11 00 00           	adcb	%al, 4416(%rax)
1000020b4: 00 00                       	addb	%al, (%rax)
1000020b6: 10 00                       	adcb	%al, (%rax)
1000020b8: e0 11                       	loopne	0x1000020cb <typeinfo for Base+0xb>
1000020ba: 00 00                       	addb	%al, (%rax)
1000020bc: 00 00                       	addb	%al, (%rax)
1000020be: 10 00                       	adcb	%al, (%rax)

00000001000020c0 <typeinfo for Base>:
1000020c0: 15 00 00 10 00              	adcl	$1048576, %eax          ## imm = 0x100000
1000020c5: 00 10                       	addb	%dl, (%rax)
1000020c7: 80 16 00                    	adcb	$0, (%rsi)
1000020ca: 00 00                       	addb	%al, (%rax)
1000020cc: 00 00                       	addb	%al, (%rax)
1000020ce: 10 80 17 00 00 10           	adcb	%al, 268435479(%rax)

00000001000020d0 <typeinfo for Der1>:
1000020d0: 17                          	<unknown>
1000020d1: 00 00                       	addb	%al, (%rax)
1000020d3: 10 00                       	adcb	%al, (%rax)
1000020d5: 00 10                       	addb	%dl, (%rax)
1000020d7: 80 18 00                    	sbbb	$0, (%rax)
1000020da: 00 00                       	addb	%al, (%rax)
1000020dc: 00 00                       	addb	%al, (%rax)
1000020de: 10 80 19 00 00 00           	adcb	%al, 25(%rax)
1000020e4: 00 00                       	addb	%al, (%rax)
1000020e6: 20 80 00 00 00 00           	andb	%al, (%rax)

00000001000020e8 <vtable for Base>:
		...
1000020f0: 19 00                       	sbbl	%eax, (%rax)
1000020f2: 00 00                       	addb	%al, (%rax)
1000020f4: 00 00                       	addb	%al, (%rax)
1000020f6: 10 80 20 12 00 00           	adcb	%al, 4640(%rax)
1000020fc: 00 00                       	addb	%al, (%rax)
1000020fe: 10 00                       	adcb	%al, (%rax)
100002100: e0 11                       	loopne	0x100002113 <vtable for Base+0x2b>
100002102: 00 00                       	addb	%al, (%rax)
100002104: 00 00                       	addb	%al, (%rax)
100002106: 00 00                       	addb	%al, (%rax)
