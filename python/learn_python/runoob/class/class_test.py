#!/usr/bin/python3

class people:
    name = ''
    age = 0

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def output(self):
        print("my name: {}, age: {}".format(self.name, self.age))

p = people("miao", 29)
p.output()
print("p name: {}".format(p.name))

print("********")

class girl(people):
    chest_circumference = 0

    def __init__(self, name, age, chest_circumference):
        people.__init__(self, name, age)
        self.chest_circumference = chest_circumference

    def output(self):
        people.output(self)
        print("my chest_circumference {}".format(self.chest_circumference))

    def print(self):
        print("my property, name:{} age:{} chest_circumference:{}".format(self.name, self.age, self.chest_circumference))

    def father_print(self):
        print("my father property, name:{}".format(people.name))

g = girl("wang", 25, 50)
g.output()
g.print()
g.father_print()

print("********")

class base:
    #private number
    __private_property = 0 
    public_property = 0

    def __init__(self, public_number, private_number):
        self.public_property = public_number
        self.__private_property = private_number

    def output(self):
        print("public number: {}, private number: {}".format(self.public_property, self.__private_property))

c = base(1, 2)
c.output()
print("print base class's obj's public number: {}".format(c.public_property))
#print("print base class's obj's private number: {}".format(c.__private_property))



