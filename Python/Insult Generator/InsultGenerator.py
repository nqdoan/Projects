import random

def insultGenerator():

   #initialize variables
   numInsults = 0
   victimName = ""
   numAdjectives = 0
   index = 0

   #bank of adjectives and nouns
   adjectiveBank = ["Adjec1", "Adjec2", "Adjec3", "Adjec4", "Adjec5", "Adjec6", "Adjec7", "Adjec8","Adjec9", "Adjec10"]
   nounBank = ["Noun1", "Noun2", "Noun3", "Noun4", "Noun5", "Noun6"]

   #get Input
   while numInsults == 0:
      numInsults = int(input("How many insults?"))
      if numInsults > 0:
         break
   while victimName == "":
      victimName = input("What is the victim's name?")
      if victimName != "":
         break
   while numAdjectives == 0:
      numAdjectives = int(input("How many adjectives should be included?"))
      if numAdjectives <= 0 and numAdjectives >= 3:
         break


   #Create full sentence
   print(victimName + " is a ")

   for i in range(0, numInsults):
      print (adjectiveBank[random.randrange(0,9)] + " ")

   for j in range(0, nounBank):
      print (nounBank[random.randrange(0,5)] + "!")

insultGenerator()
