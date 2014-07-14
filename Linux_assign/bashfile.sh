#!/bin/bash

echo $( uname -o) >> assignment.log
echo $(hostname) >> assignment.log
echo $(pwd) >> assignment.log
echo $(who) >> assignment.log
echo $(groups) >> assignment.log
echo $(ls) >> assignment.log
