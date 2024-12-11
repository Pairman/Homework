from random import shuffle as _shuffle

_adjectives = [
	"Adorable", "Amazing", "Awesome", "Beautiful", "Big", "Brave", "Bright",
	"Brilliant", "Charming", "Clean", "Clever", "Cool", "Cunning", "Cute",
	"Dazzling", "Determined", "Efficient", "Elegant", "Energetic",
	"Fabulous", "Fantastic", "Fast", "Fine", "Fresh", "Generous", "Good",
	"Gorgeous", "Great", "Handsome", "Happy", "Hot", "Incredible", "Joyful",
	"Kind", "Lovely", "Lucky", "Magnificent", "Mystic", "Neat", "Nice",
	"Noble", "Optimistic", "Passionate", "Patient", "Powerful", "Pretty",
	"Radiant", "Rich", "Secret", "Sincere", "Smart", "Solid", "Special",
	"Strategic", "Strong", "Tidy", "Trustworthy", "Wise"
]

_groceries = [
	"Apple","Apricot", "Asparagus", "Avocado", "Banana", "Beetroot",
	"Blackberry", "Blueberry", "Broccoli", "Brussels Sprout", "Cabbage",
	"Carrot", "Cauliflower", "Celery", "Cherry", "Clementine", "Coconut",
	"Cranberry", "Cucumber", "Date", "Eggplant", "Fennel", "Fig", "Garlic",
	"Grape", "Grapefruit", "Kiwi", "Leek", "Lemon", "Lettuce", "Lychee",
	"Mango", "Melon", "Mushroom", "Nectarine", "Okra", "Onion", "Orange",
	"Papaya", "Parsnip", "Passionfruit", "Peach", "Pear", "Persimmon",
	"Pineapple", "Plum", "Pomegranate", "Potato", "Pumpkin", "Quince",
	"Radish", "Raspberry", "Spinach", "Strawberry", "Tangerine", "Tomato"
]

_shuffle(_adjectives)
_shuffle(_groceries)

def get_name(seed: object):
	"""Get a random nickname.
	:param id: Hashable object.
	:return: Nickname.
	"""
	i = hash(seed)
	adjective = _adjectives[i % len(_adjectives)]
	grocery = _groceries[i % len(_groceries)]
	return f"{adjective} {grocery}"