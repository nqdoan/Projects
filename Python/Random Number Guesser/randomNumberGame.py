from random import randrange
import time

#gets input
def getInput(randomNumber):
    userInput = 0
    numbers = [0,0,0,0,0,0,0,0,0,0]
    for i in range(10):
        userInput = int(input("Enter guess " + str(i + 1) + " between 1 and 100:"))
        numbers[i] = userInput
        #Check to make sure it is not a symbol or non int
        try:
           val = int(userInput)
        except ValueError:
           print ("*** Invalid Input : Please try again...")
        #Check against duplicate numbers
        for j in range(i , 0, -1):
            if(userInput == numbers[j-1]):
               print("***Incorrent Input: cannot have a duplicate number...")
        #Check to make sure it is within 1 and 100
        if (userInput < 1) or (userInput > 100):
            print ("*** Incorrect Input: Must be in range from 1 to 100...")
        #Check to make sure it is not a decimal
        elif (userInput % 1 != 0):
            print ("*** Incorrent Input: Must be a whole number, no decimals...")
        #Check if it's within 1 and 100 and send it to randomChecker
        elif (userInput <= 100) and (userInput >= 1):
            rc = randomCheck(randomNumber, userInput)
            if(rc == 1):
                return 1
            print ("------------------------------------------")



#checks against the random number
def randomCheck(randomNumber, userInput):
    if(randomNumber == userInput):   
        print ("CORRECT!")
        print ("YOU WIN!")
        return 1
    elif(randomNumber < userInput):
        print ("Lower!")
    elif (randomNumber > userInput):
        print ("Higher!")




#main 
def main():
    game = 0
    loop = 0
    while(game == 0):
        while(loop == 0):
            randomNumber = randrange(0,100)
            print (">>> " + str(randomNumber))
            print ("Number Guessing Game ---------------------")
            gi = getInput(randomNumber)
            print ("Please wait 2 seconds.")
            time.sleep(2)
            if(gi == 1):
                break

main ()
