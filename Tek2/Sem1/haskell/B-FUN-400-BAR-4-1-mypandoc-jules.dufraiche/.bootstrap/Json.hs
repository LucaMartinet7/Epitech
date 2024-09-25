--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- Json
--
import Control.Applicative

data JsonValue
    = JsonNull
    | JsonBoolean Bool
    | JsonNumber Double
    | JsonString String
    | JsonArray [JsonValue]
    | JsonObject [(String, JsonValue)]
    deriving (Show)

data Parser a = Parser {
    runParser :: String -> Maybe (a, String)
}

instance Functor Parser where
    fmap f (Parser p) = Parser $ \s -> case p s of
        Nothing -> Nothing
        Just (res, s') -> Just (f res, s')

instance Applicative Parser where
    pure v = Parser $ \s -> Just (v, s)
    (Parser p1) <*> (Parser p2) = Parser $ \s -> case p1 s of
        Nothing -> Nothing
        Just (f, s') -> case p2 s' of
            Nothing -> Nothing
            Just (res, s'') -> Just (f res, s'')

instance Alternative Parser where
    empty = Parser $ \_ -> Nothing
    (Parser p1) <|> (Parser p2) = Parser $ \s -> p1 s <|> p2 s

instance Monad Parser where
    return = pure
    (Parser p) >>= f = Parser $ \s -> case p s of
        Nothing -> Nothing
        Just (res, s') -> runParser (f res) s'

parseTruple :: Parser (Int , Int , Int)
parseTruple = do
    parseChar '('
    a <- parseInt
    parseChar ','
    b <- parseInt
    parseChar ','
    c <- parseInt
    parseChar ')'
    return (a , b , c )

parseTuple :: Parser a -> Parser (a, a)
parseTuple p = (,) <$> p <* parseChar ',' <*> p

parseUint :: Parser Int
parseUint = read <$> parseMany (parseAnyChar ['0'..'9'])

parseInt :: Parser Int
parseInt = read <$> parseMany (parseAnyChar ['0'..'9'])

parseSome :: Parser a -> Parser [a]
parseSome p = (:) <$> p <*> parseMany p

parseAndWith :: (a -> b -> c) -> Parser a -> Parser b -> Parser c
parseAndWith f p1 p2 = f <$> p1 <*> p2

parseMany :: Parser a -> Parser [a]
parseMany p = Parser $ \str -> case runParser p str of
    Just (res, str1) -> case runParser (parseMany p) str1 of
        Just (res1, str2) -> Just (res : res1, str2)
        Nothing -> Just ([res], str1)
    Nothing -> Just ([], str)

parseAnd :: Parser a -> Parser b -> Parser (a, b)
parseAnd p1 p2 = Parser $ \str -> case runParser p1 str of
  Just (res1, str1) -> case runParser p2 str1 of
    Just (res2, str2) -> Just ((res1, res2), str2)
    Nothing -> Nothing
  Nothing -> Nothing

parseAnyChar :: String -> Parser Char
parseAnyChar chars = Parser $ \str -> case str of
  (x:xs) | x `elem` chars -> Just (x, xs)
  _ -> Nothing

parserOr :: Parser a -> Parser a -> Parser a
parserOr p1 p2 = Parser $ \str -> case runParser p1 str of
    Just res -> Just res
    Nothing -> runParser p2 str

parseChar :: Char -> Parser Char
parseChar c = Parser $ \s ->
    let s' = dropWhile (==' ') s in
    case s' of
        (x:xs) | x == c -> Just (c, xs)
        _ -> Nothing

parseJsonValue :: Parser JsonValue
parseJsonValue = parseNull <|> parseBoolean <|> parseNumber

parseNull :: Parser JsonValue
parseNull = string "null" >> return JsonNull

parseBoolean :: Parser JsonValue
parseBoolean = (string "true" >> return (JsonBoolean True)) <|> (string "false" >> return (JsonBoolean False))

parseNumber :: Parser JsonValue
parseNumber = fmap (JsonNumber . read . show) parseUint

string :: String -> Parser String
string = traverse parseChar

parseJsonArray :: Parser JsonValue
parseJsonArray = JsonArray <$> (parseChar '[' *> parseSpaces *> elements <* parseSpaces <* parseChar ']')
  where
    elements = parseJsonValue `sepBy` (parseSpaces *> parseChar ',' <* parseSpaces)
    parseSpaces = parseMany (parseChar ' ')

sepBy :: Parser a -> Parser b -> Parser [a]
sepBy p sep = (p `sepBy1` sep) <|> pure []

sepBy1 :: Parser a -> Parser b -> Parser [a]
sepBy1 p sep = (:) <$> p <*> many (sep *> p)

main :: IO ()
main = do
    print $ runParser parseJsonValue "null"
    print $ runParser parseJsonValue "true"
    print $ runParser parseJsonValue "42"
    print $ runParser parseJsonArray "[]"
    print $ runParser parseJsonArray "[1, 2, 3]"
    print $ runParser parseJsonArray "[[true, 2], [null, \"foo\"]]"