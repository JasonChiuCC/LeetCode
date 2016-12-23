private extension String {
    subscript (index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]    
    }
    var length: Int { return self.characters.count }
}

private extension Character{
    func toInt() -> Int!
    {
        return Int(String(self))
    }
}
