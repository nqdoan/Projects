import csv
import random

def gameView():
    
    print ("****** Text Adventure Game v1.0 ******")
    print ("*                                    *")
    print ("*          1 - New Game              *")
    print ("*          2 - Load Game             *")
    print ("*          3 - Quit                  *")
    print ("*                                    *")
    print ("**************************************")

def runGame(startValue, storyData, rowCount):
    
    for i in range(startValue, rowCount, 1):
        
        #Checks to see if it's the end, then chooses a random ending from what's left over in the file.
        if not(storyData[i][1]):
            randomEnding = random.randint(i, rowCount)
            print (storyData[randomEnding][0])
            break
    
        #Prints Options if they are included
        print (storyData[i][0])
        print ("1 - " + storyData[i][1])
        print ("2 - " + storyData[i][2])
        print ("3 - Save Game")
        
        #Alternative way to do above
        '''
            for j in range(1,3,1):
            print(str(j) + " - " + storyData[i][j])
            print ("3 - Save Game")
            '''
        
        
        
        ui = userInput()
        if(ui == 3):
            print (">>> Game Saved!")
            return i
            break


def userInput():
    #Gathers user input
    while True:
        try:
            userInput = int(input("What do you want to do?\n"))
            break
        except(ValueError):
            print("Error with input. Please try again!")
    return userInput


def main():
    storyData = []
    rowCount = 0
    #store data in storyData array
    infile = open("story.csv", "r")
    reader = csv.reader(infile)
    for row in reader:
        storyData.append(row)
        rowCount = rowCount + 1
    print (rowCount)


#initialize run values
game = 0
    savedStartValue = 0
    while(game == 0):
        #Start running the game, call functions gameView and userInput
        gameView()
        initialInput = userInput()
        
        #Loop for view options 1, 2 and 3
        if(initialInput == 1):
            savedStartValue = 0
            rg = runGame(savedStartValue, storyData, rowCount)
            savedStartValue = rg
        elif(initialInput == 2):
            loadGame = runGame(savedStartValue, storyData, rowCount)
        elif(initialInput == 3):
            print ("Quitting game!")


infile.close()
main()
