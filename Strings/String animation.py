import sys, time, random

base = "CRAZY STRING"
combos = ["\u0300","\u0301","\u0302","\u0308","\u0327","\u0323","\u0336","\u0332"]  # combining marks

def glitch(s, intensity=0.4):
    out = []
    for ch in s:
        out.append(ch)
        if ch != " " and random.random() < intensity:
            out.append("".join(random.choice(combos) for _ in range(random.randint(1,3))))
    return "".join(out)

try:
    for i in range(40):
        intensity = (1 + math.sin(i/4))/2 if 'math' in globals() else (0.5 + 0.5 * (i%2))
        s = glitch(base, intensity=0.4 + 0.6 * (i%4)/3)
        sys.stdout.write("\r" + s + " " * 10)
        sys.stdout.flush()
        time.sleep(0.08)
except KeyboardInterrupt:
    print("\nbye")
