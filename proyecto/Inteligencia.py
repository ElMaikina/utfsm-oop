from transformers import GPT2LMHeadModel, GPT2Tokenizer, logging
import torch

# Establecer el nivel de logging de transformers a ERROR
logging.set_verbosity_error()

# Cargar el modelo GPT-2 y el tokenizer desde Hugging Face
model_name = "gpt2"  # Puedes cambiar esto por otro modelo disponible en Hugging Face
tokenizer = GPT2Tokenizer.from_pretrained(model_name)
model = GPT2LMHeadModel.from_pretrained(model_name)

# Configurar el dispositivo para usar la GPU si está disponible
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model.to(device)

# Función para generar respuestas con el modelo GPT-2
def generar_respuesta(prompt, max_length=100, num_return_sequences=1):
    # Tokenizar la entrada
    inputs = tokenizer.encode(prompt, return_tensors="pt").to(device)
    
    # Generar el texto de salida
    outputs = model.generate(
        inputs,
        max_length=max_length,
        num_return_sequences=num_return_sequences,
        no_repeat_ngram_size=2,
        do_sample=True,
        top_k=50,
        top_p=0.95,
        temperature=0.7
    )
    
    # Decodificar el texto generado
    respuestas = [tokenizer.decode(output, skip_special_tokens=True) for output in outputs]
    return respuestas

# Ejemplo de uso
def leer_y_responder(mensaje_usuario):
    respuestas = generar_respuesta(mensaje_usuario)

    respuesta_final = ''
    for i, respuesta in enumerate(respuestas):
        respuesta_final += str(respuesta)

    #respuesta_formateada = respuestas[0].split(".")[0].split(",")[0].split("?")[1].split("\"")[0].split("\n")[-1]
    return respuesta_final.replace(str(mensaje_usuario), '').split('\n')[-1]
