{-
--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-compressor-luca.martinet [WSL: Ubuntu]
-- File description:
-- KMeans
--
-}

module KMeans
    (startAlgo, getColorDistance, generateNRandomColors, getAverageColor, getClosestCentroidIndexForColor,
    sortPixelsIntoCentroids) where

import System.Random (randomRIO)
import Data.List (elemIndex, foldl')
import GHC.Float (int2Float)
import Control.Monad (replicateM)

import Image (Pixel(..), Color(..))
import Parse (Args(..))

startAlgo :: [Pixel] -> Args -> IO [Color]
startAlgo pixels args = do
    centroids <- generateNRandomColors (argsColors args)
    return $ startKmeans pixels (argsConvergence args) centroids

calculateNewCentroids :: [Pixel] -> [Color] -> [Color]
calculateNewCentroids pixels centroids = map
    (getAverageColor . map pixelColor)
    (sortPixelsIntoCentroids pixels centroids)

calculateMaxMove :: [Color] -> [Color] -> Float
calculateMaxMove centroids newCentroids =
    maximum (zipWith getColorDistance centroids newCentroids)

startKmeans :: [Pixel] -> Float -> [Color] -> [Color]
startKmeans pixels convergence centroids
    | maxMove < convergence = newCentroids
    | otherwise = startKmeans pixels convergence newCentroids
    where
        newCentroids = calculateNewCentroids pixels centroids
        maxMove = calculateMaxMove centroids newCentroids

createPixelListsForCentroids :: [Color] -> [[Pixel]]
createPixelListsForCentroids = map (const [])

sortPixelsIntoCentroids :: [Pixel] -> [Color] -> [[Pixel]]
sortPixelsIntoCentroids pixels centroids =
  foldl
    (\acc pixel -> sortPixelIntoCentroid pixel centroids acc)
    (createPixelListsForCentroids centroids)
    (reverse pixels)

sortPixelIntoCentroid :: Pixel -> [Color] -> [[Pixel]] -> [[Pixel]]
sortPixelIntoCentroid pixel centroids pixels =
    case getClosestCentroidIndexForColor (pixelColor pixel) centroids of
        Nothing    -> pixels
        Just index -> let (before, after) = splitAt index pixels
                  in before ++ [pixel:head after] ++ tail after

getClosestCentroidIndexForColor :: Color -> [Color] -> Maybe Int
getClosestCentroidIndexForColor _ [] = Nothing
getClosestCentroidIndexForColor col centroids =
    let distances = getCentroidsDistanceForColor col centroids
    in elemIndex (minimum distances) distances

getCentroidsDistanceForColor :: Color -> [Color] -> [Float]
getCentroidsDistanceForColor col = map (getColorDistance col)

getColorDistance :: Color -> Color -> Float
getColorDistance (Color (rA, gA, bA)) (Color (rB, gB, bB)) = sqrt
    $ int2Float
        (((rA - rB) ^ (2 :: Integer))
         + ((gA - gB) ^ (2 :: Integer))
         + ((bA - bB) ^ (2 :: Integer)))

generateRandomColor :: IO Color
generateRandomColor = do
    r <- randomRIO (0, 255) :: IO Int
    g <- randomRIO (0, 255) :: IO Int
    b <- randomRIO (0, 255) :: IO Int
    return (Color (r, g, b))

generateNRandomColors :: Int -> IO [Color]
generateNRandomColors n = replicateM n generateRandomColor

getAverageColor :: [Color] -> Color
getAverageColor colors = divideColorBy
    (getSumColorOfColors colors) $ length colors

getSumColorOfColors :: [Color] -> Color
getSumColorOfColors = foldl' addColors (Color (0, 0, 0))

addColors :: Color -> Color -> Color
addColors (Color (rA, gA, bA)) (Color (rB, gB, bB)) =
    Color (rA + rB, gA + gB, bA + bB)

divideColorBy :: Color -> Int -> Color
divideColorBy col 0 = col
divideColorBy (Color (r, g, b)) denominator =
    Color (r `div` denominator, g `div` denominator, b `div` denominator)
