class Counter:
    def __init__(self, low, high):
        self.current = low
        self.high = high

    def __iter__(self):
        return self

    def next(self):
        if self.current > self.high:
            raise StopIteration
        else:
            self.current += 1
            return self.current - 1

def testCounter():
    for c in Counter(3, 8):
        print c

class Card(object):
    def __init__(self, rank, suit):
        FACE_CARD = {11: 'J', 12: 'Q', 13: 'K'}
        self.suit = suit
        self.rank = rank if rank <=10 else FACE_CARD[rank]
    def __str__(self):
        return "%s %s" % (self.rank, self.suit)
    
class Deck(object):
    def __init__(self):
        self.cards = []
        for s in ['S', 'D', 'C', 'H']:
            for r in range(1, 14):
                self.cards.append(Card(r, s))

    def __iter__(self):
        return iter(self.cards)


def oldWay():
    for c in Deck().cards:
        print c

def containerWay():
    for c in Deck():
        print c

containerWay()