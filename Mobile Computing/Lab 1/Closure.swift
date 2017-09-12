// function for sorting with out closure
let name = ["B", "A", "D", "E", "C"]

func backward(_ s1: String, _ s2: String) -> Bool {
	return s1 > s2
}

var reversedNames = name.sorted(by: backward)
print(reversedNames)


// Implematation with closure
reversedNames = name.sorted(by: { 
	(s1: String, s2: String) -> Bool in 
		return s1 > s2
})
print(reversedNames)


// inferring type from context
reversedNames = name.sorted(by: { s1, s2 in return s1 > s2})
print(reversedNames)


print("single expression closure")
reversedNames = name.sorted(by: {s1, s2 in s1>s2})
print(reversedNames)

print("short hand argument form")
reversedNames = name.sorted(by: { $0 > $1 })
print(reversedNames)

print("operator methods")
reversedNames = name.sorted(by: >)
print(reversedNames)
