class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        freq = defaultdict(int)

        for c in s:
            freq[c] += 1
        
        for c in t:
            if freq[c] == 0:
                return False
            freq[c] -= 1
        
        return True