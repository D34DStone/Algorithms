module Writer where 


newtype Writer w a = Writer { runWriter :: (a, w) }


writer :: (a, w) ->  Writer w a
writer = Writer


execWriter :: Writer w a -> w
execWriter m = snd $ runWriter m


instance Functor (Writer w) where 
    fmap f m = let (a, w) = runWriter m in writer (f a, w)


instance (Monoid w) => Applicative (Writer w) where
    pure a = writer (a, mempty)
    f <*> m = undefined 


instance (Monoid w) => Monad (Writer w) where 
    return a = writer (a, mempty)
    m >>= k = let 
        (x, l1) = runWriter m
        (y, l2) = runWriter (k x)
        in writer (y, l1 `mappend` l2)
                

tell :: (Monoid w) => w -> Writer w ()
tell l = writer ((), l)
