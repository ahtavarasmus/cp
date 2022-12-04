import os,shutil,pyperclip


    # list all the files and move that one cpp file
dest = "/Users/ahtavarasmus/cp"
temp = "/Users/ahtavarasmus/cp/template.cpp"

path = "/Users/ahtavarasmus/Downloads"

    

for file in os.listdir(path):
    if file.endswith(".cpp"):
        base,end = file.split(".")
        dest = os.path.join(dest,base)
        home = os.path.join(path,file)
        if not os.path.isdir(dest):
            os.mkdir(dest)
        text = pyperclip.paste()
        with open(dest+"/input.txt","w") as f:
            f.write(text)
            f.close()
        with open(dest+"/error.txt","x") as f:
            pass
        with open(dest+"/output.txt","x") as f:
            pass

        shutil.copy(temp,dest+"/problem.cpp")

        pyperclip.copy(dest+"/problem.cpp")
        os.remove(home)


