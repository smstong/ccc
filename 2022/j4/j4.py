#!/usr/bin/env python3

# pairs must be in the same group
X = int(input())
pairs = []
for i in range(X):
    line = input()
    pair = line.split()
    pairs.append(pair)

# paris must NOT be in the same group
Y = int(input())
noPairs = []
for i in range(Y):
    line = input()
    pair = line.split()
    noPairs.append(pair)

# test groups
G = int(input())
groups = []
for i in range(G):
    line = input()
    group = line.split()
    groups.append(group)


# return number of constraints violated
def verifyGroup(group):
    violated = 0
    for pair in pairs:
        if pair[0] in group and pair[1] not in group:
            violated += 1
    for noPair in noPairs:
        if noPair[0] in group and noPair[1] in group:
            violated += 1

    return violated

badGroups = 0
for group in groups:
    badGroups += verifyGroup(group)

print(badGroups)
