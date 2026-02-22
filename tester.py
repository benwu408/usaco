import subprocess
import os
import sys

def get_names():
    foldername = sys.argv[1] #name of folder
    if len(sys.argv) == 2:
        filename = foldername + "/" + sys.argv[1]
    elif len(sys.argv) == 3:
        filename = foldername + "/" + sys.argv[2]
    else:
        print("Usage: python3 tester.py [test folder] [filename (optional)]") #print out stuff

    return foldername, filename

def run_test(i):
    prefix = foldername + "/" + str(i) #test name

    stdin = open(prefix + ".in", "r") #open test case
    tempfile = open(temp, "w") #new temp file create

    subprocess.call([filename], stdin=stdin, stdout=tempfile) #run file with input and writing result to tempfile
    
    expected = open(prefix + ".out", "r").read() #set expected 
    result = open(temp, "r").read() #set result

    ret = 0
    if result == expected:
        ret = 1
        print ("PASSED " + str(i))
    else:
        print("FAILED " + str(i))
        # print("Expected: " + expected)
        # print("Result: " + result)

    os.remove(foldername + "/" + "temp.out") #delete temp file
    return ret


foldername, filename = get_names()

subprocess.call(["g++", "-std=c++11", "-o", filename, filename + ".cpp"]) # build file

temp = foldername + "/" + "temp.out" #name of test file out
pass_count = 0 #passed test cases

for i in range(1, 16): #loop through all tests
    pass_count += run_test(i)

if pass_count == 15: #if passed ten, say passed all
    print("PASSED ALL")
