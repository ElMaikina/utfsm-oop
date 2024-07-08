import pandas as pd

# Carga las personalitdades creadas en el archivo
def load_personalities(csv_file):
    df = pd.read_csv(csv_file)
    return df

# Obtiene una personalidad aleatoria
def get_random_personality(df):
    random_personality = df.sample(n=1).iloc[0]
    nombre_personalidad = random_personality['nombre']
    descripcion_personalidad = random_personality['descripcion']
    return nombre_personalidad, descripcion_personalidad
