from transformers import GPT2LMHeadModel, GPT2Tokenizer
import torch

# Cargar el modelo GPT-2 y el tokenizer desde Hugging Face
model_name = "gpt2"  # Puedes cambiar esto por otro modelo disponible en Hugging Face
tokenizer = GPT2Tokenizer.from_pretrained(model_name)
model = GPT2LMHeadModel.from_pretrained(model_name)

# Configurar el dispositivo para usar la GPU si está disponible
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model.to(device)

# Función para generar respuestas con el modelo GPT-2
def generar_respuesta(prompt, max_length=150, num_return_sequences=1):
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
if __name__ == '__main__':
    mensaje_usuario = "Say something happy"
    respuestas = generar_respuesta(mensaje_usuario)
    partes = respuestas[-1].split('.')
    frase = f"{partes[0].replace('\n', ' ').replace('[', '').replace(']', '').replace('\"', '')}"
    print(frase)
