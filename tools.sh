#!/bin/bash -ex

buildPath=./build
#compile use cmake
buildAll () {
	mkdir -p $buildPath && cd $buildPath && cmake .. && make -j$(nproc)&& cd -
}

runAll () {
	buildAll && find $buildPath -maxdepth 1 -type f -executable -exec {} \;
	#buildAll && find build -maxdepth 1 -type f -executable -print|bash
}
formatSrc () {
	find ./src -regex '.*\.\(c\|cc\|cpp\|h\|hpp\|cxx\)' -exec clang-format -i --style=Google {} \;
}

checkSrc () {
	find ./src -regex '.*\.\(c\|cc\|cpp\|h\|hpp\|cxx\)' -exec cpplint {} \;
}

case $1 in 
	build)
		buildAll
		;;
	run)
		runAll
		;;
	format)
	  formatSrc
		;;
	check)
		checkSrc
		;;
	*)
		echo "$0 {build|run|format|check}"
		;;
esac
