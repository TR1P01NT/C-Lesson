def getSum(self, a: int, b: int) -> int:
        while b != 0:
            a = a ^ b
            b = (a & b) << 1
    
        return a