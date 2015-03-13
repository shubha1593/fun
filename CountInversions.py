## CountInversions.py


#  getArray() 
## -----------------------------------
## Read the text file and store the numbers in each line in a list
## The number read from file is string of form "9990\r\n", so typecast to int
def getArray():
	with open("IntegerArray.txt") as f:
		numbers = f.readlines()
	numbers = map(int, numbers)
	#numbers = [1, 3, 5, 2, 4, 6, 1]
	return numbers


#  mergeAndCount(left, right)
## --------------------------------------
## Same as merge method in merge sort i.e. combine left and right sorted list
## in a single sorted list . In addition if we find the case when element of right list 
## is smaller than element in left list (right[j] < left[i]) then increase the inversion 
## count by the number of elements remaining to be traversed in the left list
def mergeAndCount(left, right):

	## length of the new single list to be formed
	total = len(left) + len(right)

	i = 0		## to iterate over left list
	j = 0		## to iterate over right list

	inversions = 0
	sortedIntegers = []		## final sorted single array
	
	for k in range(0, total):
		if i < len(left) and j < len(right) :
			if (left[i] <= right[j]) :
				sortedIntegers.append(left[i])
				i += 1

			else :
				sortedIntegers.append(right[j])
				inversions += len(left) - i
			##	print (str(left[i]) + " " + str(right[j]))
				j += 1
		else :
			if i < len(left) :
				sortedIntegers.extend(left[i : ])
			elif j < len(right) :
				sortedIntegers.extend(right[j : ])
			return (inversions, sortedIntegers)

	return (inversions, sortedIntegers)


#  getInversions(inversions, integers) 
## -------------------------------------------------
## Same as merge sort. A divide and conquer approach
## Split integer list into two halfs left and right and recursively sort and find inversions in them
def getInversions(inversions, integers):
	numOfIntegers = len(integers)
	if (numOfIntegers == 1):
		return (0, integers)

	## Inversions in which both the integers are part of left list
	leftInversions, leftIntegers = getInversions(inversions, integers[ : numOfIntegers/2 ])
	#print (str(integers[ : numOfIntegers/2]) + " " + str(leftInversions) + " sort : " + str(leftIntegers))

	## Inversions in which both the integers are part of the right list
	rightInversions, rightIntegers = getInversions(inversions, integers[ numOfIntegers/2 : ])
	#print (str(integers[numOfIntegers/2 : ]) + " " + str(rightInversions) + " sort right : " + str(rightIntegers))

	## Inversions in which one integer is from left list and the other from right list of which we take care while merging left and right
	betweenInversions, sortedIntegers = mergeAndCount(leftIntegers, rightIntegers)

	## total inversions
	inversions += leftInversions + rightInversions + betweenInversions

	return (inversions, sortedIntegers)


def countInversions():
	integerList = getArray()
	inversions, sortedIntegers = getInversions(0, integerList)
	print ("for this array inversions : " + str(inversions))
	#for k in range(0, len(sortedIntegers)) :
	#	print sortedIntegers[k]

countInversions()
