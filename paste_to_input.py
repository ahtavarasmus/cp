import pyperclip as pc
import shutil
import os

i = pc.paste()

for file in os.listdir("/Users/ahtavarasmus/Downloads"):
    if file.endswith(".cpp"):
        parent = "/Users/ahtavarasmus/cp/problems/"
        base,end = file.split(".")

        # write base name temporarely to a file so bash can open it later
        f = open(parent+"/tmp.txt","w")        
        f.write(base)
        f.close()
        path = os.path.join(parent,base)

        if not os.path.isdir(path):
            os.mkdir(path)

        f = open(path+"/input.txt","w")
        f.write(i)
        f.close()
        f = open(path+"/error.txt","w")
        f.close()
        f = open(path+"/output.txt","w")
        f.close()
        f = open(path+"/problem.cpp","w")
        f.close()
        shutil.copy("/Users/ahtavarasmus/cp/template.cpp",path+"/problem.cpp")
        
        
        os.remove("/Users/ahtavarasmus/Downloads/"+file)
        break

        


