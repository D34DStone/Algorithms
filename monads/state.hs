module State where 


newtype State s a = State { runState :: s -> (a, s) }


execState :: State s a -> s -> s
execState m = \s -> snd $ runState m s


evalState :: State s a -> s -> a
evalState m = \s -> fst $ runState m s


instance Functor (State s) where 
    fmap f m = undefined


instance Applicative (State s) where 
    pure = undefined 
    f <*> m = undefined


instance Monad (State s) where 
    return a = State $ \s -> (a, s)
    m >>= k = State $ \s -> let 
        (x, s') = runState m s
        in runState (k x) s'


get :: State s s
get = State $ \s -> (s, s)


put :: s -> State s ()
put s = State $ \_ -> ((), s)
