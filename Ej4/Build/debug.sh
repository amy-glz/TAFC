
cmake ../Ejercicio4
make -j4 >output.log 2>&1

git add output.log
git commit -m "output"
git push

echo "debug"
