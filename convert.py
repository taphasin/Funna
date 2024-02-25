to_remov = {"A": "4", "E": "3", "I": "1", "S": "5", "T" : "7", "G" : "9", "O" : "0", "R" : "2"}
to_Tran =  {"4": "A", "3": "E", "1": "I", "5": "S", "7" : "T", "9" : "G", "0" : "O", "2" : "R"}

def Convert(string):
    genstr = string
    for char in to_remov.keys():
        Nstr = genstr.replace(char, to_remov[char])
        genstr = Nstr
    return Nstr

def Translate(string):
    genstr = string
    for char in to_Tran.keys():
        Nstr = genstr.replace(char, to_Tran[char])
        genstr = Nstr
    return Nstr

print("Translate(T) or Convert(C) :")
func = input()

print("input : ")
string = input()
string = string.upper()
print(string)

if func == "T":
    print("Altered string: " +Translate(string))
elif func == "C":
    print("Altered string: " +Convert(string))

#this commit 2/25/2024