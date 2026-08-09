{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BAR-3-1-PDGRUSH1-luca.martinet
-- File description:
-- main
-}

import System.Exit (exitWith, ExitCode(ExitFailure))
import System.Environment (getArgs)
import Data.List (sort)
import Text.Read (readMaybe)
import Data.Monoid (mappend)

type Operation = ([Int], [Int]) -> ([Int], [Int])

swapList :: [Int] -> [Int]
swapList [] = []
swapList [a] = [a]
swapList (a: b: c) = b: a: c

mySa :: Operation
mySa (listA, listB) = (swapList listA, listB)

mySb :: Operation
mySb (listA, listB) = (listA, swapList listB)

mySc :: Operation
mySc (listA, listB) = (swapList listA, swapList listB)

myPa :: Operation
myPa (listA, []) = (listA, [])
myPa (listA, (a:b)) = ((a : listA), b)

myPb :: Operation
myPb ([], listB) = ([], listB)
myPb ((a:b), listB) = (b, a:listB)

myRa :: Operation
myRa ([], listB) = ([], listB)
myRa (x:xs, listB) = (mappend xs [x], listB)

myRb :: Operation
myRb (listA, []) = (listA, [])
myRb (listA, bx:bxn) = (listA, mappend bxn [bx])

myRr :: Operation
myRr (listA, listB) = myRb(myRa(listA, listB))

myRra :: Operation
myRra ([], listB) = ([], listB)
myRra (listA, listB) = ((last listA : init listA), listB)

myRrb :: Operation
myRrb (listA, []) = (listA, [])
myRrb (listA, listB) = (listA, (last listB : init listB))

myRrr :: Operation
myRrr (listA, listB) = myRrb(myRra(listA, listB))

checkNum :: [String] -> Bool
checkNum [] = True
checkNum (arg:args)
    | (readMaybe arg :: Maybe Int) == Nothing = False
    | otherwise = checkNum args

checkArgs :: [String] -> Bool
checkArgs [] = False
checkArgs (args) = checkNum args

checkOps :: String -> Bool
checkOps [] = True
checkOps operations = all (`elem` ["sa", "sb", "sc", "pa", "pb",
    "ra", "rb", "rr", "rra", "rrb", "rrr"]) (words operations)

strToInt :: [String] -> [Int]
strToInt = map (read :: String -> Int)

checkSorted :: [Int] -> Bool
checkSorted xs = xs == sort xs

checkResult :: ([Int], [Int]) -> Bool
checkResult ([], _) = False
checkResult (listA, listB)
    | not (null listB) = False
    | otherwise = checkSorted listA

printSwap :: ([Int], [Int]) -> IO ()
printSwap (listA, listB)
    | checkResult (listA, listB) = putStrLn "OK"
    | otherwise = putStrLn ("KO:" ++ show (listA, listB))

operationChoice :: String -> Operation
operationChoice "sa" = mySa
operationChoice "sb" = mySb
operationChoice "sc" = mySc
operationChoice "pa" = myPa
operationChoice "pb" = myPb
operationChoice "ra" = myRa
operationChoice "rb" = myRb
operationChoice "rr" = myRr
operationChoice "rra" = myRra
operationChoice "rrb" = myRrb
operationChoice "rrr" = myRrr

applyOperation :: ([Int], [Int]) -> String -> ([Int], [Int])
applyOperation currentState ops = operationChoice ops currentState

processOperations :: ([Int], [Int]) -> [String] -> ([Int], [Int])
processOperations initialState ops = foldl applyOperation initialState ops

loop :: ([Int], [Int]) -> [String] -> IO ()
loop initialState operations =
    printSwap (processOperations initialState operations)

checks :: [String] -> String -> IO ()
checks args operations
    | checkArgs args == False = exitWith (ExitFailure 84)
    | checkOps operations == False = exitWith (ExitFailure 84)
    | otherwise = loop (strToInt args, []) (words operations)

main :: IO ()
main = do
    args <- getArgs
    operations <- getContents
    checks args operations
