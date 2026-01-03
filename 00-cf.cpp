import sys

def read_seed(default=0):
    data = sys.stdin.read().strip()
    if not data:
        return default
    try:
        return int(data.split()[0])
    except:
        return default

def main():
    seed = read_seed(default=0)

    from sklearn.datasets import load_breast_cancer
    from sklearn.model_selection import train_test_split
    from sklearn.linear_model import LogisticRegression
    from sklearn.metrics import accuracy_score
    import pandas as pd

    data = load_breast_cancer()
    X = pd.DataFrame(data.data, columns=data.feature_names)
    y = pd.Series(data.target)

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.2, random_state=seed, stratify=y
    )

    model = LogisticRegression(solver='liblinear', max_iter=1000, random_state=seed)
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)

    acc = accuracy_score(y_test, y_pred)
    print(acc)

if __name__ == "__main__":
    main()
