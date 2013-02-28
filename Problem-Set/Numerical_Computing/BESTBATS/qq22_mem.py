import sys

class BESTBATS():

    def __init__(self):
        #inputData = open('input.txt')
        inputData = sys.stdin
        numTestCases = int(inputData.readline())
        for tc in range(0,numTestCases):
            self.playerScores = sorted([int(score) for score in inputData.readline().split()], reverse = True)
            self.numPlayers = int(inputData.readline())
            self.maxScore = sum(self.playerScores[:self.numPlayers])
            self.possibleScores = []
            for i in range(0,len(self.playerScores)-self.numPlayers+1):
                self.findPossibleScores(i,[])
            print len(self.possibleScores)
            
    def findPossibleScores(self,index,possibleScores):
        possibleScores.append(self.playerScores[index])
        if len(possibleScores) == self.numPlayers and sum(possibleScores) == self.maxScore:
            self.possibleScores.append(list(possibleScores))
        else:
            for i in range(index+1,len(self.playerScores)):
                self.findPossibleScores(i,possibleScores)
        possibleScores.pop()
                            
if __name__ == '__main__':
    b = BESTBATS()