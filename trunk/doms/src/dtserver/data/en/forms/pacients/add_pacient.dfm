<Form title="Ingresar paciente" >
	<HBox>
		<Image filename="logo.svg" />
		<Input type="date" />
		<VBox>
			<Input label="Nombres" dbfield="user:login" />
			<Input label="Apellidos" dbfield="user:password" />
		</VBox>
	</HBox>
	<VGroupBox title="Informacion personal" >
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
				<RadioButton label="Cedula extrajera" />
				<RadioButton label="Pasaporte" />
				<Input label="No." />
			</VGroupBox>
		</HBox>
		<HBox>
			<Input label="Direccion de residencia" />
			<Input label="Municipio" />
		</HBox>
		<HBox>
			<Input label="Telefono de residencia"  />
			<Input label="Movil" />
			<Input label="E-Mail" />
		</HBox>
		<HBox>
			<Input label="Ocupacion" />
			<Input label="Telefono oficina" />
		</HBox>
	</VGroupBox>
	<VGroupBox title="Referencias personales" >
		<HBox>
			<Input label="Persona responsable" />
			<Input label="Parentesco" />
			<Input label="telefono" />
			<Input label="ocupacion" />
		</HBox>
		<HBox>
			<Input label="Persona de referencia" />
			<Input label="Parentesco" />
			<Input label="telefono" />
			<Input label="ocupacion" />
		</HBox>
	</VGroupBox>
</Form>

