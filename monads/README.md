## Monads 
Computation context in haskell.

### Defenition 
```haskell
class Applicative m => Monad (m :: * -> *) where
  (>>=) :: m a -> (a -> m b) -> m b
  (>>) :: m a -> m b -> m b
  return :: a -> m a
  fail :: String -> m a
```

### Monad laws
```haskell
return a >>= k                  = k a
m >>= return                    =  m
m >>= (\x -> k x >>= h)         =  (m >>= k) >>= h
```


### Useful syntax shugar
We can write chain of computations like that:
```haskell
a = m >>=
    k1 >>=
    k2 >>= 
    ... 
    >>= kn
```

Using third monoid law we can write so:
```haskell
a = m >>= (\x1 -> 
    k1 x1 >>= (\x2 -> 
    k2 x1 >>= (\x3 -> 
    ...
    kn xm)...) 
```

But there is too many trash in out code so we can use do-notation:
```haskell
a = do 
    x1 <- k1 v
    x2 <- k2 x1
    ... 
```
