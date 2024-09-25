{-
--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-compressor-luca.martinet
-- File description:
-- Main
--
-}


module Main (main) where

import Image (parseImageContent, Pixel(..), Color(..))
import Parse (getOpt, Args(argsFile))
import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(ExitFailure), exitSuccess)
import System.IO.Error (tryIOError)
import Control.Exception ()
import KMeans (startAlgo, sortPixelsIntoCentroids)

exitError :: String -> IO ()
exitError msg = putStrLn msg >> exitWith (ExitFailure 84)

readImage :: String -> IO (Either String String)
readImage file = do
    result <- tryIOError (readFile file)
    return $ case result of
        Left _ -> Left "Invalid file"
        Right content -> Right content

processImage :: String -> Args -> IO ()
processImage file args = readImage file >>= \image ->
    case image of
        Left err -> exitError err
        Right content ->
            let pixels = parseImageContent content
            in if content /= "" && not (null pixels)
                then startAlgo pixels args
                    >>= displayClusters pixels >> exitSuccess
                else exitError "Invalid image"

main :: IO ()
main = getArgs >>= \inputArgs ->
    case getOpt inputArgs of
        Nothing -> exitError "Invalid arguments"
        Just args -> processImage (argsFile args) args

displayCluster :: ([Pixel], Color) -> IO ()
displayCluster (cluster, centroid) =
    putStrLn ("--\n" ++ show centroid ++ "\n-") >> mapM_ print cluster

displayClusters :: [Pixel] -> [Color] -> IO ()
displayClusters pixels centroids =
    mapM_ displayCluster
        (zip (sortPixelsIntoCentroids pixels centroids) centroids)

--testing btw dont care bout this
-- main :: IO ()
-- main = do
--   args <- getArgs
--   let conf = getOpt args
--   case conf of
--     Nothing -> exitError "Invalid configuration"
--     Just conf -> do
--       content <- try (readFile (argsFile conf)) :: IO (Either IOException String)
--       case content of
--         Left _ -> exitError "Invalid file"
--         Right content -> do
--           -- Print the result of parseImage.
--           printParseImageResult content
