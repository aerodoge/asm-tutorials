.PHONY: build


######################################################################	
max:
	as 02maximum.s -o build/maximum.o
	ld build/maximum.o -o build/maximum

runmax: max
	@echo "运行程序..."
	./build/maximum || echo "程序退出代码: $$?"

######################################################################

min:
	as 03minimum.s -o build/minimum.o
	ld build/minimum.o -o build/minimum

runmin: min
	@echo "运行程序..."
	./build/minimum || echo "程序退出代码: $$?"

######################################################################
pow-x86:
	@echo "编译..."
	as --32 04pow_x86.s -o build/pow_x86.o
	ld -m elf_i386 build/pow_x86.o -o build/pow_x86 
runpow-x86: pow-x86
	@echo "运行程序..."
	./build/pow_x86 || echo "程序退出代码: $$?"

######################################################################
pow-x64:
	@echo "编译..."
	as 04pow_x64.s -o build/pow_x64.o
	ld build/pow_x64.o -o build/pow_x64 
runpow-x64: pow-x64
	@echo "运行程序..."
	./build/pow_x64 || echo "程序退出代码: $$?"

######################################################################
clean:
	rm -rf build/*





