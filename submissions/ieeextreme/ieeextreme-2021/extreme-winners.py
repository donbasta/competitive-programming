# print(["m ","ps","aS","pr","AT","gs","ra","Us","mN","mE","te","dC","Co","or"].index(input()[3:5])+1)

# import re;print(re.findall('..',"m psaSprATgsraUsmNmEtedCCoor").index(input()[3:5])+1)

# print(map(''.join, zip(*[iter("m psaSprATgsraUsmNmEtedCCoor")]*2)).index(input()[3:5])+1)

# l = "m psaSprATgsraUsmNmEtedCCoor"
# print([l[i:i+2] for i in range(0, len(l), 2)].index(input()[3:5])+1)

# "m psaSprATgsraUsmNmEtedCCoor"

# 1        Team 1
# @        Knapsackers@UNT
# M        MoraSeekers
# p        SurpriseTeam
# C        CuSAT
# D        DongskarPedongi
# c        cofrades
# R        viRUs
# T        TeamName
# e        TeamEPFL1
# w        whatevs
# W        WildCornAncestors
# h        TheCornInTheFields
# A        Aurora

# import re;print(re.findall('.',"1@MpCDcRTewWhA").index(input()[3:5])+1)

print("1@MpCDcRTewWhA".index(list(input())+1))

l=input();for i in range(14): if l[i] in j: print(i + 1); break

j=input()
l="1@MpCDcRTewWhA"
for i in range(14): 
    if l[i] in j: 
        print(i + 1)
        break