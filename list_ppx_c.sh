for archivo in ./src/*.c; do
	if [ -f "$archivo" ]; then
		echo "========================================"
		echo "ARCHIVO: $archivo"
		echo "========================================"
		cat "$archivo"
		echo "\n"
	fi
done
