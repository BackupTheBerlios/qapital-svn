<Form title="Historia Clinica" >
	<HBox>
		<Image filename="logo.svg" />
		<VBox>
			<Label text="Historia clinica" />
			<Input label="No." />
			<Input label="Odontologo" />
		</VBox>
	</HBox>
	<HBox>
		<Input type="date" />
		<VBox>
			<Input label="Nombres" />
			<Input label="Apellidos" />
		</VBox>
	</HBox>
	<HBox>
		<VGroupBox title="Sexo" >
			<RadioButton label="Masculino" />
			<RadioButton label="Femenino" />
		</VGroupBox>
		<VGroupBox title="Estado civil" >
			<RadioButton label="Soltero" />
			<RadioButton label="Casado" />
			<RadioButton label="Viudo" />
			<RadioButton label="Union libre" />
		</VGroupBox>
		<VGroupBox title="Documento de identidad" >
			<RadioButton label="Tarjeta de identidad" />
			<RadioButton label="Cedula de ciudadania" />
			<RadioButton label="C.E." />
			<RadioButton label="Pasaporte" />
			<Input label="No." />
		</VGroupBox>
	</HBox>
	<Label text="Marque lo que tenga" />
	<VGroupBox title="Enfermedades" >
		<CheckBox label="Alergias" />
		<CheckBox label="Transtornos de coagulacion" />
		<CheckBox label="Enfermedades respiratorias " />
		<CheckBox label="Alteraciones cardiacas " />
		<CheckBox label="Fiebre reumatica " />
		<CheckBox label="Cirugias " />
		<CheckBox label="Enfermedad Renal " />
		<CheckBox label="Hepatitis " />
		<CheckBox label="Transtornos gastricos " />
		<CheckBox label="Hipertension " />
	</VGroupBox>
</Form>

