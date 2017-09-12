func chooseStepFunction(backward: Bool) -> (Int) -> Int {
	func sf(input: Int) -> Int {
		return input + 1
	}
	
	func sb(input: Int) -> Int {
		return input - 1
	}
	
	return backward ? sb : sf
}

var currentValue = -4
let moveNearZero = chooseStepFunction(backward: currentValue > 0)

while currentValue != 0 {
	print("\(currentValue)...")
	currentValue = moveNearZero(currentValue)
}