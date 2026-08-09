{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BAR-3-1-PDGD01-luca.martinet
-- File description:
-- My hs project day 1
-}

mySucc :: Int -> Int
mySucc nb = nb + 1

myIsNeg :: Int -> Bool
myIsNeg nb = if nb < 0 then True else False

myAbs :: Int -> Int
myAbs nb = if nb < 0 then -nb else nb

myMin :: Int -> Int -> Int
myMin nb1 nb2 = if nb1 > nb2 then nb2 else nb1

myMax :: Int -> Int -> Int
myMax nb1 nb2 = if nb1 > nb2 then nb1 else nb2

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (a:_) = a
myHead [] = error "Empty list"

myTail :: [a] -> [a]
myTail (_:a) = a
myTail [] = error "Empty list"

myLength :: [a] -> Int
myLength (_:a) = 1 + myLength a
myLength [] = 0

myNth :: [a] -> Int -> a
myNth (a:b) i
    | i < 0 = error "Index negative"
    | i > myLength(b) + 1 = error "Index too high"
myNth (a:b) 0 = a
myNth (a:b) i = (myNth b (i - 1))

myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake a (b:c)
    | a <= 0 = []
myTake a (b:c) = b : myTake (a - 1) c

myDrop :: Int -> [a] -> [a]
myDrop a [] = []
myDrop a (b:c) = if a == 1 then c else myDrop (a - 1) c

myAppend :: [a] -> [a] -> [a]
myAppend [] a = a
myAppend (b:c) a = b : myAppend c a

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend (myReverse b) [a]

myInit :: [a] -> [a]
myInit [] = error "Empty list"
myInit a = myReverse (myDrop 1 (myReverse a))

myLast :: [a] -> a
myLast [] = error "Empty list"
myLast a = myHead (myReverse a)

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (a:b) (c:d) = myTuple a c : myZip b d

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a, b):c) = myTuple(a:myFst(myUnzip c)) (b:mySnd(myUnzip c))
