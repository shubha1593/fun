## QuickSort.py
# ----------------------------------------------------

## Reads the text file "QuickSort.txt" where every single line stores an integer.
def getNumList():
	with open("QuickSort.txt") as f:
		numbers = f.readlines()
	# Cast numbers type from string to integer
	numbers = map(int, numbers)
	#numbers = [1, 3, 5, 2, 4, 6, 1]
	return numbers


## Swaps the ith and jth element of numlist
def swap(numList, i, j) :
	temp = numList[i]
	numList[i] = numList[j]
	numList[j] = temp


def getMedian(numlist, start, end) :
	if end - start < 2 :
		return start
	middle = ((end - start) / 2) + start

	##### SHORTER WAY : Sort and return the center index but as this is a sorting program let's stick to the longer method
	## Took help from stack overflow to get the indexes in the order of sorted element values
	#sortedIndex = sorted([start, middle, end], key=lambda k : numlist[k])
	##print "sortedIndex : " + str(sortedIndex)
	#return sortedIndex[1]

	##### LONGER WAY to get the median 
  if numlist[start] < numlist[middle] and numlist[start] < numlist[end] :
		if numlist[middle] < numlist[end] :
			return middle
		else :
			return end
	if numlist[middle] < numlist[start] and numlist[middle] < numlist[end] :
		if numlist[start] < numlist[end] :
			return start
		else :
			return end
	if numlist[end] < numlist[start] and numlist[end] < numlist[middle] :
		if numlist[start] < numlist[middle] :
			return start
		else :
			return middle
 
 
def choosePivot(numlist, start, end) :
	## CASE 1: First elem as pivot
	## ---------------------------------------------------------
	#pivotIndex = start

	## CASE 2: Last elem as pivot
	## ---------------------------------------------------------
	#pivotIndex = end

	## CASE 3: Median of first, middle and last elem as pivot
	## ---------------------------------------------------------
	pivotIndex = getMedian(numlist, start, end)

	return pivotIndex


def partitionList( numlist, start, end) :
	i = start + 1
	j = start + 1

	while j <= end :
		if numlist[j] >= numlist[start] :
			j += 1
		else :
			swap(numlist, i, j)
			i += 1
			j += 1

	swap(numlist, start, i - 1)

	return i - 1


## start and end are indices , start indicating begining of the list remaining to be sorted 
## and end indicating 
def quickSort(numList, start, end) :
	if end - start <= 0 :
		return 

	global numOfComparisions

	## returns index of pivot chosen
	pivot = choosePivot(numList, start, end)
	swap(numList, start, pivot)
	
	finalPivotLoc = partitionList(numList, start, end)
	
	numOfComparisions += end - start
	
	quickSort(numList, start, finalPivotLoc - 1)
	
	quickSort(numList, finalPivotLoc + 1, end)
	


#numlist = [8, 2, 4, 5, 7, 1]
numOfComparisions = 0
numlist = getNumList()
quickSort(numlist, 0, len(numlist) - 1)
#print " list : " + str(numlist)
print "numOfComparisions : " + str(numOfComparisions)
