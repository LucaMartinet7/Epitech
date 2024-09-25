{-
--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-compressor-luca.martinet [WSL: Ubuntu]
-- File description:
-- Image
--
-}

module Image(parseImageContent, Position(..), Color(..), Pixel(..)) where
import Data.Char (isDigit)
import Data.Maybe (mapMaybe)

instance Show Pixel where
    show pixel = show (pixelPosition pixel) ++ " " ++ show (pixelColor pixel)

instance Show Color where
    show (Color (r, g, b)) =
        "(" ++ show r ++ "," ++ show g ++ "," ++ show b ++ ")"

instance Show Position where
    show (Position (x, y)) = "(" ++ show x ++ "," ++ show y ++ ")"

data InvalidPixel = InvalidPixel deriving Show

type FilePixel = Either InvalidPixel Pixel

newtype Color = Color (Int, Int, Int) deriving (Eq)

newtype Position = Position (Int, Int)

data Pixel = Pixel {pixelPosition :: Position, pixelColor :: Color}

removeExtraSpaces :: String -> String
removeExtraSpaces = filter (/= ' ')

removeNonDigits :: String -> String
removeNonDigits = map replaceNonDigit
        where
                replaceNonDigit x = if isDigit x then x else ' '

convertDataToPixel :: [String] -> FilePixel
convertDataToPixel [x, y, r, g, b]
        | not $ all (\e -> e >= 0 && e <= 255) [sr, sg, sb] = Left InvalidPixel
        | otherwise = Right
                Pixel { pixelPosition = Position (read x :: Int, read y :: Int)
                                        , pixelColor = Color (sr, sg, sb)
                                        }
        where
                sr = read r :: Int
                sg = read g :: Int
                sb = read b :: Int
convertDataToPixel _ = Left InvalidPixel

convertLineToData :: String -> FilePixel
convertLineToData x
        | length ws /= 5 = Left InvalidPixel
        | otherwise = convertDataToPixel ws
        where
                ws = words x

convertFilePixelToPixel :: [FilePixel] -> [Pixel]
convertFilePixelToPixel = mapMaybe toPixel
        where
                toPixel (Right pixel) = Just pixel
                toPixel _ = Nothing

hasInvalidPixel :: [FilePixel] -> Bool
hasInvalidPixel = any isInvalidPixel
        where
                isInvalidPixel (Left InvalidPixel) = True
                isInvalidPixel _ = False

parseLinesToPixels :: [String] -> [Pixel]
parseLinesToPixels line =
        let content = map convertLineToData line
        in if hasInvalidPixel content
                 then []
                 else convertFilePixelToPixel content

parseImageContent :: String -> [Pixel]
parseImageContent content =
    parseLinesToPixels $
        map removeNonDigits $ words (removeExtraSpaces content)

--testing purpose dont forget to import to the main
-- printParseImageResult :: String -> IO ()
-- printParseImageResult content = print (parseImage content)