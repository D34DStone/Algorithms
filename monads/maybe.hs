module Maybe' where 

data Maybe' a = Just' a | Nothing' deriving Show


instance Functor Maybe' where
    fmap _ Nothing' = Nothing'
    fmap f (Just' a) = Just' (f a)


instance Applicative Maybe' where 
    pure = Just'
    Nothing' <*> _ = Nothing'
    _ <*> Nothing' = Nothing'
    (Just' f) <*> (Just' a) = Just'(f a)


instance Monad Maybe' where 
    return = pure
    Nothing' >>= _ = Nothing'
    (Just' a) >>= k = case k a of
        Nothing' -> Nothing' 
        v -> v


decrease :: Int -> Int -> Maybe' Int
decrease a b 
    | b < a = Nothing'
    | otherwise = Just' (b - a)
    
