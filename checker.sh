#!/bin/bash

make build

amestecare_sum=0

for i in {1..10}
do
    cp "tests/tests_amestecare/test$i.in" ./in
    make run
    if diff -w ./out "tests/tests_amestecare/test$i.ref" > /dev/null 2>&1
    then
        echo "Testul $i Amestecare...............................PASSED"
        amestecare_sum=$(( $amestecare_sum + 4 ))
    else
        echo "Testul $i Amestecare...............................FAILED"
    fi
done
echo ""
echo "Ai obtinut $amestecare_sum/40 pe Amestecare!"
echo ""

razboi_sum=0
for i in {1..4}
do
    cp "tests/tests_razboi/razboi$i.in" ./in
    make run
    if diff -w ./out "tests/tests_razboi/razboi$i.ref" > /dev/null 2>&1
    then
        echo "Testul $i Razboi..................................PASSED"
        razboi_sum=$(( $razboi_sum + 5 ))
    else
        echo "Testul $i Razboi..................................FAILED"
    fi
done

echo ""
echo "Ai obtinut $razboi_sum/20 pe Război!"
echo ""

rs_sum=0
for i in {1..4}
do
    cp "tests/tests_rolling_stone/rollingstone$i.in" ./in
    make run
    if diff -w ./out "tests/tests_rolling_stone/rollingstone$i.ref" > /dev/null 2>&1
    then
        echo "Testul $i Rolling Stone..................................PASSED"
        rs_sum=$(( $rs_sum + 5 ))
    else
        echo "Testul $i Rolling Stone..................................FAILED"
    fi
done

echo ""
echo "Ai obtinut $rs_sum/20 pe Rolling Stone!"
echo ""

scara_sum=0
for i in {1..4}
do
    cp "tests/tests_scarabei/scarabei$i.in" ./in
    make run
    if diff -w ./out "tests/tests_scarabei/scarabei$i.ref" > /dev/null 2>&1
    then
        echo "Testul $i Scarabei..................................PASSED"
        scara_sum=$(( $scara_sum + 5 ))
    else
        echo "Testul $i Scarabei..................................FAILED"
    fi
done

echo ""
echo "Ai obtinut $scara_sum/20 pe Scarabei!"
echo ""

echo "Total: $(( $amestecare_sum + $razboi_sum + $rs_sum + $scara_sum ))/100"