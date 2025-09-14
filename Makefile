.PHONY: build


######################################################################
maximum.o:
	as 02maximum.s -o build/maximum.o

max: maximum.o
	ld build/maximum.o -o build/maximum

runmax: max
	@echo "运行程序..."
	./build/maximum || echo "程序退出代码: $$?"
######################################################################
minimum.o:
	as 03minimum.s -o build/minimum.o

min: minimum.o
	ld build/minimum.o -o build/minimum

runmin: min
	@echo "运行程序..."
	./build/minimum || echo "程序退出代码: $$?"
######################################################################



clean:
	rm -rf build/*



