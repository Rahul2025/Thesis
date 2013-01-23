# imports
import sys
import StringIO

class Problem(object):
    def __init__(self, reader):        
        self.reader = reader

    def run(self):                
        vowels = frozenset(["a",  "e",  "i",  "o",  "u"])
        last_vowel_block = -1
        # decode the message, by replacing the vowel pattterns
        for i, letter in enumerate(  self.reader.readline().strip() ) :
            if i > last_vowel_block :
                if letter in vowels:
                    last_vowel_block = i + 2
                sys.stdout.write(letter)
        

# Main entry point
############################################################ 
if __name__ == "__main__":
    #data = StringIO.StringIO("""razat geze hozotazamnaza ozoraza bezehizisaza""")
    data = sys.stdin

    problem = Problem(data)
    problem.run()