import cs50
import csv
import sys

if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")

database = []

# read dict data into memory
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file)
    for row in reader:
        database.append(row)

# get the STR list 
str_base = list(database[0].keys())
str_base.remove('name')

# read sequence into memory
with open(sys.argv[2]) as file2:
    sequence = file2.read()

# define function that check each position in the sequence and output the maxium number of consecutive STRs
def compare_seq(sequence, proto):
    max_str = 0
    for i in range(len(sequence)):
        n_str = 0
        while i < len(sequence):
            str_candidate = sequence[i:i+len(proto)]
            if str_candidate == proto:
                n_str += 1
                i += len(proto)
            else:
                max_str = max(max_str, n_str)
                break
    return max_str

max_str = []
for i in range(len(str_base)):
    max_str.append(compare_seq(sequence, str_base[i]))

name = 'No match'
for d in database:
    flag = False
    for i in range(len(str_base)):
        if max_str[i] == int(d[str_base[i]]):
            if i == len(str_base) - 1:
                name = d['name']
                flag = True
                break
            continue
        else:
            break
    if flag:
        break
        
print(name)
